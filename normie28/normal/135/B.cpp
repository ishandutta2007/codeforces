#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e6 + 5)
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
typedef unsigned long long ull;
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
 
int dist(pii a, pii b) {
 
        return sq(a.fr - b.fr) + sq(a.sd - b.sd);
}
 
int isSquare(vector<pii> X) {
 
        sort(ALL(X));
        do{
 
                int ok = 1;
                for(int i = 0; i + 1 < 4; i++)
                        if(dist(X[i], X[i + 1]) != dist(X[0], X[3]))
                                ok = 0;
 
                if(dist(X[0], X[2]) != 2 * dist(X[0], X[1]) || dist(X[1], X[3]) != 2 * dist(X[0], X[1]))
                        ok = 0;
 
                REP(i, 4) {
 
                        REPN(j, 3, i + 1)
                                if(dist(X[i], X[j]) == 0)
                                        ok = 0;
                }
 
                if(ok)
                        return 1;
 
        } while(next_permutation(ALL(X)));
        return 0;
}
 
int isRect(vector<pii> X) {
 
        sort(ALL(X));
        do {
 
                int ok = 1;
 
                if(dist(X[0], X[1]) != dist(X[2], X[3]) || dist(X[1], X[2]) != dist(X[0], X[3]))
                        ok = 0;
 
                if(dist(X[0], X[2]) != dist(X[1], X[3]))
                        ok = 0;
 
                REP(i, 4) {
 
                        REPN(j, 3, i + 1)
                                if(dist(X[i], X[j]) == 0)
                                        ok = 0;
                }
 
                if(ok)
                        return 1;
 
        } while(next_permutation(ALL(X)));
 
        return 0;
}
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pii> pts(8);
 
        for(pii &x : pts)
                cin >> x.fr >> x.sd;
 
        REP(i, 1 << 8) {
 
                vector<pii> A, B;
                vector<int> X, Y;
 
                REP(j, 8) {
 
                        if(i & (1 << j))
                                A.pb(pts[j]), X.pb(j + 1);
                        else
                                B.pb(pts[j]), Y.pb(j + 1);
                }
 
                if(X.size() == 4 && isSquare(A) && isRect(B)) {
 
                        cout << "YES\n";
                        for(int u : X)
                                cout << u << " " ;
 
                        cout << endl;
                        for(int u : Y)
                                cout << u << " " ;
                        cout << endl;
                        return 0;
                }
 
        }
 
        cout << "NO\n" ;
        return 0;
}