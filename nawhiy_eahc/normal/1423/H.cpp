#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,Q,k,cnt[500005],cnt2[500005],dep[100005],p[100005];
int ti[500005],sti[500005],eti[500005],LL[500005];
int vis[100005],sz[100005];
int q[500005];
vector <int> ans;
vector <pi> t[2000005];
stack <pair<pi,pi>> st;

struct LifeS {int x,y,s,e;};
vector <LifeS> life;

int Find(int x) {
	if(p[x] == x) return x;
	return Find(p[x]);
}

int merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return 0;
	if(dep[x] < dep[y]) swap(x,y);
	p[y] = x;
	sz[x] += sz[y];
	if(dep[x] == dep[y]) {
		dep[x]++; st.push({{x,y},{1,sz[y]}});
	}
	else st.push({{x,y},{0,sz[y]}});
	return 1;
}

void add(int node,int l,int r,int rl,int rr,pi x) {
	if(l > rr||rl > r) return;
	if(rl <= l&&r <= rr) {
		t[node].push_back(x);
		return;
	}
	int mid = (l + r) >> 1;
	add(node*2,l,mid,rl,rr,x), add(node*2+1,mid+1,r,rl,rr,x);
}

void Rollback(int cntt) {
	for(int i = 1;i <= cntt;i++) {
		auto j = st.top(); st.pop();
		sz[j.x.x] -= j.y.y;
		p[j.x.y] = j.x.y;
		if(j.y.x) dep[j.x.x]--;
	}
}

void query(int node,int l,int r) {
	int cntt = 0;
	for(auto i : t[node]) cntt += merge(i.x,i.y);
	if(l == r) {
		cout << sz[Find(q[l])] << '\n';
		Rollback(cntt);
		return;
	}
	int mid = (l + r) >> 1;
	query(node*2,l,mid); query(node*2+1,mid+1,r);
	Rollback(cntt);
}

struct qqq {
	int x,y,s,e;
};
vector <qqq> qq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q >> k;
	for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1, dep[i] = 0;
	cnt[0] = 1;
	for(int i = 1;i <= Q;i++) {
		int op,x,y;
		cin >> op;
		if(op == 1) {
			cin >> x >> y;
			if(x > y) swap(x,y);
			qq.pb({x,y,i,cnt[i-1]+k-1});
		}
		else if(op == 2) {
			eti[cnt[i-1]] = cnt2[i-1]+1;
			cin >> x, cnt2[i] = 1, ti[cnt2[i-1]+1] = cnt[i-1], q[cnt2[i-1]+1] = x;
		}
		else LL[cnt[i-1]+1] = i, cnt[i] = 1;
		cnt[i] += cnt[i-1];
		cnt2[i] += cnt2[i-1];
		eti[cnt[i]] = max(eti[cnt[i]],eti[cnt[i-1]]);
	}
	for(qqq i : qq) {
		if(i.e > cnt[Q]) i.e = cnt[Q];
		add(1,1,cnt2[Q],cnt2[i.s]+1,eti[i.e],{i.x,i.y});
	}
	query(1,1,cnt2[Q]);
}