#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int Q = 100000;
int can[N];

ll diq(ll n, ll k){
    return (n + k - 1) / k;
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m ; i ++ ){
        can[i]=-1;
    }
    int typ;
    ll x;
    int y;
    ll nex;
    for(int iq = 1; iq <= n; iq ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> x >> y;
            for(int j = m ; j >= 0 ; j -- ){
                if(can[j] != -1){
                    nex = j;
                    for(int a = 1; a <= y; a ++ ){
                        nex = diq(nex * 1ll * Q + x, Q);
                        if(nex > m) break;
                        if(can[nex] != -1) break; // will be looked at later
                        can[nex] = iq;
                    }
                }
            }
        }
        else{
            cin >> x >> y;
            for(int j = m ; j >= 0 ; j -- ){
                if(can[j] != -1){
                    nex = j;
                    for(int a = 1; a <= y; a ++ ){
                        nex = diq(nex * 1ll * x, Q);
                        if(nex > m) break;
                        if(can[nex] != -1) break; // will be looked at later
                        can[nex] = iq;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= m ; i ++)
        cout << can[i] << " ";
    cout << "\n";
    return 0;
}