#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];

int col[N];

int p[N];

int in[N];
int out[N];
int tt;

void dfs(int u, int par){
	in[u] = tt;
	p[tt] = col[u];
	tt ++ ;
	for(auto x : T[u]){
		if(x != par){
			dfs(x, u);
		}
	}
	out[u] = tt - 1;
}

int BL = 350; 

struct Query{
	int left_bound;
	int right_bound;
	int kmin;
	int index;
	bool operator< (const Query &A){
		if(left_bound / BL == A.left_bound / BL){
			return right_bound < A.right_bound;
		}
		else{
			return left_bound < A.left_bound;
		}
	}
};

int idx[N];
int blok[1000];

void update(int u, int d){
	idx[u] += d;
	blok[u / BL] += d;
}

int ask(int l, int r){
	int ret = 0;
	while(l <= r && l % BL != 0){
		ret += idx[l];
		l ++ ;
	}
	while(l + BL - 1 <= r){
		ret += blok[l / BL];
		l += BL;
	}
	while(l <= r){
		ret += idx[l];
		l ++ ;
	}
	return ret;
}

int cnt[N];

void change(int u, int d){
	update(cnt[p[u]], -1);
	cnt[p[u]] += d;
	update(cnt[p[u]], +1);
}

int main(){
	fastIO;
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++ ){
		cin >> col[i];
	}
	int u , v;
	for(int i = 1 ; i < n; i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1, -1);
	Query qr[q];
	int ans[q];
	int nd, vk;
	for(int i = 0 ; i< q ; i ++ ){
		cin >> nd >> vk;
		qr[i].left_bound = in[nd];
		qr[i].right_bound = out[nd];
		qr[i].kmin = vk;
		qr[i].index = i;
	}
	sort(qr, qr + q);
	int cl = 0, cr = -1;
	int tl, tr;
	for(int t = 0; t < q; t ++ ){
		tl = qr[t].left_bound;
		tr = qr[t].right_bound;
		while(cl < tl) change(cl ++ , -1);
		while(cl > tl) change(-- cl ,  1);
		while(cr < tr) change(++ cr ,  1);
		while(cr > tr) change(cr -- , -1);
		ans[qr[t].index] = ask(qr[t].kmin, n);
	}
	for(int i = 0 ;i < q; i ++ )
		cout << ans[i] << "\n";
	
	return 0;
}