#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int LOG = 20;
int par[LOG][N];

int A[N];
int C[N];

int main(){
    int q;
    cin >> q >> A[0] >> C[0];
    int typ;
    int ned;
    ll total;
    ll val;
    int node;
    int go, nex;
    int take;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> par[0][iq] >> A[iq] >> C[iq];
            for(int i = 1; i < LOG; i ++ ){
                par[i][iq] = par[i-1][par[i-1][iq]];
            }
        }
        else{
            cin >> node >> ned;
            total = 0;
            val = 0;
            while(ned > 0){
                go = node;
                for(int lg = LOG - 1; lg >= 0 ; lg -- ){
                    nex = par[lg][go];
                    if(A[nex] > 0){
                        go = nex;
                    }
                }
                if(A[go] == 0) break;
                take = min(A[go], ned);
                A[go] -= take;
                ned -= take;
                val += take;
                total += take * 1ll * C[go];
            }
            cout << val << " " << total << endl;
        }
    }
    return 0;
}