#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = N * 200, inf = 1e9;
int n, m, ch[M][2], mn[M], tot;
struct node {
	int l, r, v;
	node (int L = 0, int R = 0, int V = 0) {
		l = L, r = R, v = V;
	}
} ;

void modify(int &id, int L, int R, int x, int v) {
	if(!id) id = ++tot, mn[id] = inf;
	mn[id] = min(mn[id], v);
	if(L == R) return;
	int mid = (L + R) >> 1;
	if(x <= mid) modify(ch[id][0], L, mid, x, v);
	else modify(ch[id][1], mid + 1, R, x, v);
}

void ADD(int id, int L, int R, int x, int y, int v) {
	modify(id, 1, n, y, v);
	if(L == R) return;
	int mid = (L + R) >> 1;
	if(x <= mid) ADD(id * 2, L, mid, x, y, v);
	else ADD(id * 2 + 1, mid + 1, R, x, y, v); 
}

int query(int id, int L, int R, int l, int r) {
	if(!id || l > R || L > r) return inf;
	if(l <= L && R <= r) return mn[id];
	int mid = (L + R) >> 1;
	return min(query(ch[id][0], L, mid, l, r), query(ch[id][1], mid + 1, R, l, r));
}

int QRY(int id, int L, int R, int l, int r) {
	if(l > R || L > r) return inf;
	if(l <= L && R <= r) return query(id, 1, n, l, r);
	int mid = (L + R) >> 1;
	return min(QRY(id * 2, L, mid, l, r), QRY(id * 2 + 1, mid + 1, R, l, r));
}

vi v[N];
int sl[N], sr[N], Ns[N];

queue < node > q;
void Push(int pl, int pr) {
	if(pl <= pr) {
		int val = QRY(1, 1, n, pl, pr);
		if(val <= m) {
			q.push(node(pl, pr, val)); 
		}	
	}
}
int calc() {
	int ns = 0;
	Push(1, n);
	while(!q.empty()) {
		node u = q.front();
		q.pop();
		ns += sr[u.v] - sl[u.v] + 1;
		Push(u.l, sl[u.v] - 1);
		Push(sr[u.v] + 1, u.r);
	}
	return ns;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, tot = n * 4;
	memset(mn, 0x3f, sizeof(mn));
	L(i, 1, m) {
		cin >> sl[i] >> sr[i];
		v[sr[i] - sl[i] + 1].push_back(i);
	}
	R(i, n, 1) {
		for(const int &x : v[i]) ADD(1, 1, n, sl[x], sr[x], x);
		Ns[i] = calc();
	}
	L(i, 1, n) cout << Ns[i] << "\n"; 
	return 0;
}