#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 2e5 + 10;
int af[maxn], bf[maxn], sf[maxn];
int Ta[4 * maxn], Tb[4 * maxn], Ts[4 * maxn];
int s[maxn];

int F(int *T, int L, int R, int id, int idx){
    T[id] ++;
    if(R - L == 1)
        return 0;
    int mid = (L + R) >> 1;
    if(idx < mid)
        return F(T, L, mid, id * 2, idx);
    else
        return F(T, mid, R, id * 2 + 1, idx) + T[id * 2];
}

int G(int L, int R, int id, int idx){
    Ts[id] ++;
    if(R - L == 1){
        return L;
    }
    int mid = (L + R) >> 1;
    if(mid - L - Ts[id * 2] >= idx)
        return G(L, mid, id * 2, idx);
    else
        return G(mid, R, id * 2 + 1, idx - (mid - L - Ts[id * 2]));
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    rep(i, n)
        cin >> a[i];
    rep(i, n)
        cin >> b[i];
    rep(i, n){
        af[n - i - 1] = a[i] - F(Ta, 0, n, 1, a[i]);
        bf[n - i - 1] = b[i] - F(Tb, 0, n, 1, b[i]);
    }

    rep(i, n){
        sf[i] += af[i] + bf[i];
        sf[i + 1] += sf[i] / (i + 1);
        sf[i] %= i + 1;
    }

    for(int i = n - 1; i >= 0; i--)
        s[n - i - 1] = G(0, n, 1, sf[i] + 1);
    rep(i, n)
        cout << s[i] << ' ';
    cout << endl;
    return 0;
}