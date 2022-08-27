#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7, M = N * 75;
int n, m, q;

int ch[M][2], sum[M], srt, rt[N], tot;
void add (int & Id, int p, int w) {
	if(!Id) Id = ++tot;
	int id = Id;
	sum[id] += w;
	R(i, 29, 0) {
		if(!ch[id][p >> i & 1]) 
			ch[id][p >> i & 1] = ++tot;
		id = ch[id][p >> i & 1], sum[id] += w;
	}
}
int query (int x, int y, int z) {
	if(sum[x] - sum[y] - sum[z] == 0) return -1;
	ll ret = 0;
	R(i, 29, 0) {
		if(sum[ch[x][0]] - sum[ch[y][0]] - sum[ch[z][0]]) 
			x = ch[x][0], y = ch[y][0], z = ch[z][0];
		else 
			x = ch[x][1], y = ch[y][1], z = ch[z][1], ret += 1 << i;
	} 
	return ret;
}

struct querys {
	int opt, u, v, w;
} qry[N];

vector < int > ve[N << 2];
void Add(int id, int L, int R, int l, int r, int Id) {
	if(l <= L && R <= r) return ve[id].push_back(Id), void();
	int mid = (L + R) >> 1;
	if(l <= mid) Add(id << 1, L, mid, l, r, Id); 
	if(r > mid) Add(id << 1 | 1, mid + 1, R, l, r, Id);
}

mt19937_64 orz(time(0) ^ clock());
unordered_map< ll, int > mp;
ll base;
ll hashing (int x, int y) {
	return x * base + y; 
}

multiset < int > st[N];
ll ns = 3e9;
void upd (int x) {
	if(sz(st[x]) >= 3) {
		auto l = st[x].begin();
		ll ret = * l;
		++l, ret += *l, ++l, ret += *l; 
		ns = min(ns, ret);
	} 
}

void mk (int x, int y, int w, int val) {
	if(val == 1) st[x].insert(w), st[y].insert(w), upd(x), upd(y);
	else st[x].erase(st[x].find(w)), st[y].erase(st[y].find(w));
	
	if (val == 1) {
		ll t = query (srt, rt[x], rt[y]); 
		if(t != -1) ns = min(ns, w + t);
	}
	add (srt, w, val);
	add (rt[x], w, val);
	add (rt[y], w, val);
} 
void dfs(int id, int L, int R) {
	int mid = (L + R) >> 1;
	ll ret = ns;
	for (int p : ve[id]) mk (qry[p].u, qry[p].v, qry[p].w, 1);
	if (L == R) {
		if(L >= m) cout << ns << "\n";
	}
	else dfs(id << 1, L, mid), dfs(id << 1 | 1, mid + 1, R);
	ns = ret; 
	for (int p : ve[id]) mk (qry[p].u, qry[p].v, qry[p].w, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, q = m; 
	base = orz() % (n * 5 + 1) + n;
	
	L(i, 1, q) {
		if(i <= m) qry[i].opt = 1;
		else cin >> qry[i].opt;
		
		cin >> qry[i].u >> qry[i].v;
		
		if(qry[i].opt == 1) 
			cin >> qry[i].w;
		
		if(i == m) 
			cin >> q, q += m;
		
		if (qry[i].u > qry[i].v)
			swap(qry[i].u, qry[i].v);

		ll now = hashing (qry[i].u, qry[i].v);

		if (qry[i].opt == 1) 
			mp[now] = i;

		if (qry[i].opt == 0)
			Add(1, 1, q, mp[now] <= m ? 1 : mp[now], i - 1, mp[now]), mp.erase(now);
	}

	for (auto p : mp)
		Add(1, 1, q, p.second <= m ? 1 : p.second, q, p.second);

	dfs(1, 1, q);
	return 0;
}