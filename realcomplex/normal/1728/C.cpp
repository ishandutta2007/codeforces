#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first 
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> aa, bb;

void mult(){
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    multiset<int> xx;
    for(auto x : aa){
        xx.insert(x);
    }
    aa.clear();
    vector<int> nb;
    for(auto x : bb){
        if(xx.count(x)){
            xx.erase(xx.find(x));
        }
        else{
            nb.push_back(x);
        }
    }
    for(auto x : xx) aa.push_back(x);
    bb = nb;
}

int len(int y){
    int res = 0;
    while(y > 0){
        y /= 10;
        res ++ ;
    }
    return res;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int x;
        aa.clear();
        bb.clear();
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            aa.push_back(x);
        }
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            bb.push_back(x);
        }
        mult();
        int soln = 0;
        for(auto &x : aa){
            if(x >= 10) {
                soln ++ ;
                x = len(x);
            }
        }
        for(auto &x : bb){
            if(x >= 10){
                soln ++ ;
                x = len(x);
            }
        }
        mult();
        for(auto &x : aa) if(x != 1) soln ++ ;
        for(auto &x : bb) if(x != 1) soln ++ ;
        cout << soln << "\n";
    }
    return 0;
}