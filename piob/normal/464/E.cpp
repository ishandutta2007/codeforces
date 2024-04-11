#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;

struct node {
	node *left, *right;
	unsigned val;
	bool full;
};

node *zero;

struct khash {
	unsigned operator()(const PUU& k) const {
		return hash<unsigned>()(k.st) ^ (hash<unsigned>()(k.nd) << 1);
	}
};

unordered_map<PUU, unsigned, khash> id;

unsigned get_id(int a, int b){
	if(id.find(PUU(a,b)) == id.end()){
		unsigned s = id.size();
		return id[PUU(a,b)] = s;
	}
	return id[PUU(a,b)];
}

node* make(node* a, node* b){
	return new node({a, b, get_id(a->val, b->val), a->full && b->full});
}

pair<node*, bool> add(node* u, int b, int s=128*1024){
	if(s==32)
		return make_pair(new node({0, 0, u->val+(1<<b), u->val+(1<<b) == (1LL<<32)}), u->val > u->val+(1<<b));
	if(u->full && b==0){
		node *z = zero;
		for(int i=128*1024; i>s; i/=2) z = z->left;
		return make_pair(z, 1);
	}
	if(b < s/2){
		pair<node*, bool> r = add(u->left, b, s/2);
		if(r.nd){
			pair<node*, bool> q = add(u->right, 0, s/2);
			return make_pair(make(r.st, q.st), q.nd);
		}
		return make_pair(make(r.st, u->right), 0);
	}else{
		pair<node*, bool> r = add(u->right, b-s/2, s/2);
		return make_pair(make(u->left, r.st), r.nd);
	}
}

LL P2[64*1024+3];

LL res(node *u, int s=128*1024){
	if(s==32) return u->val % mod;
	return (res(u->left, s/2) + res(u->right, s/2) * P2[s/2]) % mod;
}

node* make_zero(int s=128*1024){
	if(s==32)
		return new node({0,0,0,0});
	node* v = make_zero(s/2);
	return new node({v,v,0,0});
}

bool shorter(const node* a, const node *b){
	if(a->val == b->val) return 0;
	if(!a->left) return a->val < b->val;
	if(a->right->val == b->right->val) return shorter(a->left, b->left);
	return shorter(a->right, b->right);
}

const int MAXN = 100010;

int n, m;
vector<PII> E[MAXN];
node* dist[MAXN];
bool vis[MAXN];
bool reach[MAXN];
int pre[MAXN];

typedef pair<node*, int> elem;
struct comp{
	bool operator()(elem a, elem b){
		return shorter(b.st, a.st);
	}
};
priority_queue<elem, vector<elem>, comp> Q;

void check(int p, int u, node* new_dist){
	if(vis[u]) return;
	if(!reach[u] || shorter(new_dist, dist[u])){
		reach[u] = 1;
		pre[u] = p;
		dist[u] = new_dist;
		Q.push(make_pair(new_dist, u));
	}
}

int main(){
	id[PII(0,0)] = 0;
	P2[0] = 1;
	FWD(i,1,64*1024+3) P2[i] = P2[i-1] * 2 % mod;
	zero = make_zero();
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		E[a].push_back(PII(b,c));
		E[b].push_back(PII(a,c));
	}
	int s, t;
	scanf("%d %d", &s, &t);
	check(0, s, zero);
	while(!Q.empty()){
		int u = Q.top().nd;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(PII e : E[u])
			check(u, e.st, add(dist[u], e.nd).st);
	}
	if(!reach[t])
		printf("-1\n");
	else{
		printf("%d\n", (int)res(dist[t]));
		vector<int> path;
		int u = t;
		while(u){
			path.push_back(u);
			u = pre[u];
		}
		printf("%d\n", (int)path.size());
		while(!path.empty()){
			printf("%d ", path.back());
			path.pop_back();
		}
	}
	return 0;
}