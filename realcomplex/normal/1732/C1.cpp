#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];
ll P[N];
ll Q[N];

ll f(int l, int r){
    return P[r] - P[l - 1] - (Q[r] ^ Q[l - 1]);
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
        Q[i] = (Q[i - 1] ^ A[i]);
    }
    ll maxi = f(1, n);
    int en;
    int li = 1;
    int ri = n;
    cin >> li >> ri;
    int sz = n;
    int chk;
    for(int l = 1; l <= n; l ++ ){
        if(f(l, n) == maxi){
            en = n;
            for(int lg = 18 ;lg >= 0 ; lg -- ){
                chk = en - (1 << lg);
                if(chk >= l && f(l, chk) == maxi){
                    en = chk;
                }
            }
            if(en - l + 1 < sz){
                sz = en - l + 1;
                li = l;
                ri = en;
            }
        }
    }
    cout << li << " " << ri << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}