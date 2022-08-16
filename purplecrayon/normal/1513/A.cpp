#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 31, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, k;
vector<int> adj[MAXN];
ll a[MAXN];

void solve(){
    int n, k; cin >> n >> k;
    if (k > (n-1)/2) { cout << -1 << '\n'; return; }
    else {
        vector<int> a(n); int c=0;
        for (int i = 0; i < n; i += 2) a[i] = c++;
        for (int i = 1; i < n; i += 2) a[i] = c++;
        if (k < n/2){
            int j = 1+2*k;
            sort(a.begin()+j-1, a.end());
        }
        for (auto& it : a) cout << it+1 << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}