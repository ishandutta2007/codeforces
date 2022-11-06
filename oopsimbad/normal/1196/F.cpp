#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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

const int MAXN = 200005;
vector<pii> adj[MAXN];
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	F0R(i, m) {
		int a, b, c; cin >> a >> b >> c;
		adj[a-1].pb(mp(c,b-1));
		adj[b-1].pb(mp(c,a-1));
	}
	priority_queue<pair<ll,piii>, vector<pair<ll,piii>>, greater<pair<ll,piii>>> pq;
	F0R(i, n) {
		sort(adj[i].begin(), adj[i].end());
		pq.push(mp(adj[i][0].f,mp(i,mp(i,0))));
	}
	set<piii> s;
	set<pii> s2;
	int cnt = 0;
	while(!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		pii cur = mp(p.s.f, adj[p.s.s.f][p.s.s.s].s);
		if(s.find(p.s) != s.end()) continue;
		s.insert(p.s);
		if(adj[p.s.s.f][p.s.s.s].s > p.s.f && s2.find(cur) == s2.end()) {
			s2.insert(cur);
			if(++cnt == k) {
				cout << p.f << endl;
				break;
			}
		}
		if(p.s.s.s != adj[p.s.s.f].size()-1) {
			piii np = mp(p.s.f, mp(p.s.s.f, p.s.s.s+1));
			pq.push(mp(p.f+adj[p.s.s.f][p.s.s.s+1].f-adj[p.s.s.f][p.s.s.s].f, np));
		}
		piii np = mp(p.s.f, mp(adj[p.s.s.f][p.s.s.s].s,0));
		if(s.find(np) == s.end())
			pq.push(mp(p.f+adj[adj[p.s.s.f][p.s.s.s].s][0].f, np));	
	}
///
	cin >> n;
	return 0;
}