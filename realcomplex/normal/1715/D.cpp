#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int LOG = 30;
int A[N];
vector<pii> adj[N];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int i, j, x;
    for(int i = 1; i <= n; i ++ ){
        A[i] = (1 << LOG) - 1;
    }
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> i >> j >> x;
        adj[i].push_back(mp(j, x));
        adj[j].push_back(mp(i, x));
        for(int lg = 0 ; lg < LOG; lg ++ ){
            if((x & (1 << lg)) == 0){
                A[i] &= ((1 << LOG) - 1 - (1 << lg));
                A[j] &= ((1 << LOG) - 1 - (1 << lg));
            }
        }
    }

    bool keep;
    for(int i = 1; i <= n; i ++ ){
        for(int lg = 0 ; lg < LOG; lg ++ ){
            if((A[i] & (1 << lg))){
                keep = true;
                for(auto p : adj[i]){
                    if((A[p.fi] & (1 << lg)) == 0 || p.fi == i){
                        keep = false;
                    }
                }
                if(keep){
                    A[i] ^= (1 << lg);
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}