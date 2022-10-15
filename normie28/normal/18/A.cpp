#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(2e2 + 5)
#define MAXM (int)(1e2+5)
#define fr first
#define sd second
#define MP make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define M0(a) memset(a, 0, sizeof(a))
#define M1(a) memset(a, -1, sizeof(a))
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REPN(i,n,m) for(int i = m; i <= int(n); i++)
#define RREP(i,n) for(int i = int(n-1); i >= 0; i--)
#define RREPN(i, n, m) for(int i = n; i >= (int)m; i--)
typedef long long ll;
typedef double db;
typedef long double ld;
const ll INF= ll(1e11 + 7);
const ll MOD = ll(1e9 + 7);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppii;
template<typename T, typename U> inline void AMIN(T &x, U y){ if(x > y) x = y;}
template<typename T, typename U> inline void AMAX(T &x, U y){ if(x < y) x = y;}
 
int sq(int a) {
        return a * a;
}
 
int dist(pii a,  pii b) {
 
        return sq(a.fr - b.fr) + sq(a.sd - b.sd);
}
 
int pyth(pii a,  pii b, pii c) {
 
        vector<int> d = {dist(a, b), dist(a, c), dist(b, c)};
        sort(ALL(d));
 
        if(!d[0] || !d[1] || !d[2])
                return 0;
 
        return d[0] + d[1] == d[2];
}
 
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void popu(vector<pii> &B) {
 
        if(!B.size())
                return;
        pii X = B.back();
        B.pop_back();
 
        REP(i, 4) {
 
                B.pb({X.fr + dx[i], X.sd + dy[i]});
        }
}
 
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pii> ref;
 
        REP(i, 3) {
 
                int x, y;
                cin >> x >> y;
                ref.pb({x, y});
        }
 
        int ok = pyth(ref[0], ref[1], ref[2]);
 
        if(ok) {
 
                cout << "RIGHT\n";
                return 0;
        }
 
        REP(i, 3) {
 
                vector<pii> A, B;
                REP(j, 3) {
 
                        if(i != j)
                                A.pb(ref[j]);
                        else
                                B.pb(ref[j]);
 
                }
 
                popu(B);
                for(pii X : B)
                        ok |= pyth(A[0], A[1], X);
 
        }
 
        if(ok) {
 
                cout << "ALMOST\n";
                return 0;
        }
        else {
 
                cout << "NEITHER\n";
                return 0;
        }
 
        return 0;
}