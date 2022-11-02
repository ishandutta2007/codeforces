#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#define MAX 100000
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
#define m 998244353
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

map<int, pair<int, int>> getData;
pair<int, int> ask(int i, int j){
    cout << "? " << i+1 << ' ' << j+1 << endl;
    cout.flush();
    int predict;
    cin >> predict;
    return getData[predict];
}

int main(){
    int magic[] = {4, 8, 15, 16, 23, 42};
    for(int i=0;i<6;i++){
        for(int j=i+1; j<6; j++){
            getData[magic[i] * magic[j]] = pair<int, int>{i, j};
        }
    }
    int P[6];
    pair<int, int> temp = ask(0, 1);
    P[0] = temp.fi;
    P[1] = temp.se;
    temp = ask(2, 3);
    P[2] = temp.fi;
    P[3] = temp.se;
    bool cnt[6] = {false};
    for(int i=0;i<4;i++){
        cnt[P[i]] = true;
    }
    for(int i=0;i<6;i++){
        if(!cnt[i]){
            P[4] = i;
            cnt[i] = true;
            break;
        }
    }
    for(int i=0;i<6;i++){
        if(!cnt[i]){
            P[5] = i;
            cnt[i] = true;
            break;
        }
    }
    temp = ask(0, 2);
    if(temp.fi == P[0] || temp.fi == P[1]){
        if(temp.fi == P[1]){
            swap(P[0], P[1]);
        }
        if(temp.se == P[3]){
            swap(P[2], P[3]);
        }
    }else{
        if(temp.se == P[1]){
            swap(P[0], P[1]);
        }
        if(temp.fi == P[3]){
            swap(P[2], P[3]);
        }
    }
    temp = ask(2, 4);
    if(temp.fi == P[2] || temp.fi == P[3]){
        if(temp.fi == P[3]){
            swap(P[2], P[3]);
        }
        if(temp.se == P[5]){
            swap(P[4], P[5]);
        }
    }else{
        if(temp.se == P[3]){
            swap(P[2], P[3]);
        }
        if(temp.fi == P[5]){
            swap(P[4], P[5]);
        }
    }
    cout << "! ";
    for(int i=0;i<6;i++){
        cout << magic[P[i]] << ' ';
    }
    cout << endl;
    return 0;
}