#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int val[N];

int n;

int ask(int x){
    if(x == 0 || x == n + 1){
        return (int)1e9;
    }
    else{
        if(val[x] != 0) return val[x];
        int q;
        cout << "? " << x << endl;
        cin >> q;
        val[x]=q;
        return q;
    }
}

int main(){

    cin >> n;
    int cur = 1;
    int nx;
    for(int lg = 18; lg >= 0; lg -- ){
        nx = (cur + (1 << lg));
        if(nx <= n){
            if(ask(nx) >= ask(nx + 1)){
                cur = nx;
            }
        }
    }
    while(ask(cur) >= ask(cur+1))cur ++ ;
    cout << "! " << cur << endl << "\n";
    return 0;
}