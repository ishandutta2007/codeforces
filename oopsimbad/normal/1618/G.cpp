#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

ll psum[400005];
int par[400005];
int sz[400005];
ll sum;

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

ll calc(int x) {
    ll res = psum[x];
    if(x - sz[x] >= 0)  res -= psum[x-sz[x]];
    return res;
}

void uni(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    ll change = calc(x) + calc(y);
    if(x < y) {
        int t = x;
        x = y;
        y = t;
    }
    sz[x] += sz[y];
    par[y] = x;
    sum += calc(x) - change;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, Q; cin >> N >> M >> Q;

    vector<pii> v;
    sum = 0;
    F0R(i, N) {
        int a; cin >> a;
        v.pb(mp(a, 1));
        sum += a;
    }
    F0R(i, M) {
        int a; cin >> a;
        v.pb(mp(a, 0));
    }

    sort(v.begin(), v.end());

    vector<pii> next;
    F0R(i, v.size()-1)
        next.pb(mp(v[i+1].f-v[i].f, i));

    sort(next.begin(), next.end());

    vector<pii> q;
    F0R(i, Q) {
        int a; cin >> a;
        q.pb(mp(a, i));
    }
    sort(q.begin(), q.end());

    ll ans[Q];

    psum[0] = v[0].f;
    FOR(i,1, N+M) {
        psum[i] = psum[i-1] + v[i].f;
    }
    F0R(i, N+M) {
        par[i] = i;
        sz[i] = v[i].s;
    }
    
    int ni = 0;
    F0R(i, Q) {
        while(ni < N+M && next[ni].f <= q[i].f) {
            uni(next[ni].s, next[ni].s+1);
            ni++;
        }
        ans[q[i].s] = sum;
    }

    for(auto x : ans)
        cout << x << endl;

	return 0;
}