#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    ll n, k;
    int m;
    cin >> n >> m >> k;
    queue<ll> rem;
    ll x;
    for(int i = 1; i <= m; i ++ ){
        cin >> x;
        -- x;
        rem.push(x);
    }
    ll has = 0;
    ll id;
    ll tt = 0;
    ll opr = 0;
    while(!rem.empty()){
        id = rem.front() - has;
        tt = 1;
        opr ++ ;
        rem.pop();
        while(!rem.empty()){
            if((rem.front() - has) / k == id / k){
                tt ++ ;
                rem.pop();
            }
            else{
                break;
            }
        }
        has += tt;
    }
    cout << opr;
    return 0;
}