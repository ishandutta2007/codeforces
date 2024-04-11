#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii; 
typedef pair<ll, ll> pll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 500005;
vector<int> adj[MAXN];
int arr[MAXN], dep[MAXN], in[MAXN], ans[MAXN];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int times; cin >> times;
    F0R(asdf, times) {
        int n; cin >> n;
        F0R(i, n) {
            adj[i].clear();
            cin >> arr[i];
            dep[i] = 0;
            in[i] = 0;
        }
        stack<piii> s;
        F0R(i, n) {
            while(!s.empty() && s.top().s.s <= i) s.pop();
            if(arr[i] != -1 && arr[i] != n+1) {
                adj[arr[i]-1].pb(i);
                in[i]++;
            }
            if(!s.empty()) {
                piii p = s.top();
                dep[i] = p.f;
                adj[p.s.f].pb(i);
                in[i]++;
            }
            if(arr[i] != -1) {
                s.push(mp(dep[i],mp(i,arr[i]-1)));
            }
        }
        int v = n;
        vector<int> q;
        F0R(i, n) if(in[i] == 0) q.pb(i);
        F0R(a, q.size()) {
            int i =q[a];
            ans[i] = v--;
            for(int j : adj[i])
                if(--in[j] == 0) q.pb(j);
        }
        if(v != 0) cout << -1;
        else F0R(i, n) cout << ans[i] << ' ';
        cout << endl;
    }
    
    return 0;
}