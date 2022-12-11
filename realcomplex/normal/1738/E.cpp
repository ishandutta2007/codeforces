#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1e5 + 10;
const int MOD = 998244353;
const int M = (int)2e5 + 10;
int fac[M];
ll a[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int go(int a, int b){
    int q = fac[a + b];
    q = (q * 1ll * powr(fac[a], MOD - 2)) % MOD;
    q = (q * 1ll * powr(fac[b], MOD - 2)) % MOD;
    return q;
}


int get(int i, int j){
    if(i == j + 1) return 1;
    if(i > j + 1) return 0;
    if(a[i] == 0 && a[j] == 0){
        int tl = i;
        int tr = j;
        while(a[tl] == 0 && tl <= j){
            tl ++ ;
        }
        while(a[tr] == 0 && tr >= i){
            tr -- ;
        }
        if(tl > tr){
            return powr(2, j - i);
        }
        int ww = get(tl, tr);
        return (go(tl - i, j - tr) * 1ll * ww) % MOD;
    }
    ll sa = 0;
    ll sb = 0;
    int tl = i;
    int tr = j;
    while(sa != sb || sa == 0){
        if(sa < sb || sa == 0){
            sa += a[tl];
            tl ++ ;
        }
        else if(sb < sa){
            sb += a[tr];
            tr -- ;
        }
    }
    if(tl > tr + 1){
        return 1;
    }
    int ql = tl;
    int qr = tr;
    if(tl <= tr){
        while(ql <= tr && a[ql] == 0) ql ++ ;
        while(qr >= tl && a[qr] == 0) qr -- ;
        if(ql > tr) {
            return powr(2, tr - tl + 2);
        }
    }
    else{
        return 2;
    }
    return (get(ql, qr) * 1ll * (go(ql - tl + 1, tr - qr + 1))) % MOD;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    cout << get(1, n) << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    fac[0] = 1;
    for(int i = 1; i < M; i ++ ){
        fac[i]=(fac[i-1] * 1ll * i) % MOD;
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}