#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())
#define mp make_pair

const int N = (int)1e5 + 9;
vector<pii> T[N];

ll d[N];
int pv[N];
bool ok[N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int a, b, w;
	for(int i = 0 ;i  < m ; i ++ ){
		cin >> a >> b >> w;
		T[a].push_back(mp(b, w));
		T[b].push_back(mp(a, w));
	}
	for(int i = 1; i <= n; i ++ )
		d[i] = (ll)1e14;
	for(int i = 1; i <= n; i ++ )
		pv[i] = -1;
	priority_queue<pii, vector<pii>, greater<pii>> st;
	st.push(mp(0, 1));
	d[1] = 0;
	int nd;
	ll ds;
	while(!st.empty()){
		nd = st.top().se;
		ds = st.top().fi;
		st.pop();
		if(ok[nd])
			continue;
		ok[nd] = true;
		for(auto x : T[nd]){
			if(d[nd] + x.se < d[x.fi]){
				d[x.fi] = d[nd] + x.se;
				pv[x.fi] = nd;
				st.push(mp(d[x.fi], x.fi));
			}
		}
	}
	if(pv[n] == -1){
		cout << -1;
		return 0;
	}
	vector<int> id;
	int p = n;
	do{
		id.push_back(p);
		p = pv[p];
	}while(p != 1);
	id.push_back(1);
	for(int i = id.size() - 1;i >= 0 ;i -- ){
		cout << id[i] << " ";
	}
	return 0;
}