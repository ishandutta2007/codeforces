#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    ll a[n];
    rep(i, n)
        cin >> a[i];
    cin >> m;
    ll b[m + 1];
    rep(i, m)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int p = 0, q = 0;
    ll scra, scrb = 3 * m, ansa = 3 * n, ansb = 3 * m;
    ll dis = 3 * (n - m);
    b[m] = -1;
    while(q < m){
        while(b[q] == b[q + 1])
            q ++;
        while(a[p] <= b[q] && p < n)
            p ++;
        scra = 2 * p + 3 * (n - p);
        scrb = 2 * (q + 1) + 3 * (m - q - 1);
        if(scra - scrb > dis){
            ansa = scra;
            ansb = scrb;
            dis = scra - scrb;
        }
        q ++;
    }
    cout << ansa << ':' << ansb << endl;
    return 0;
}