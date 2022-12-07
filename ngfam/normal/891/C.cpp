#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

struct data{
	int u;
	int v;
	int w;
	int can;
	int idx;

	bool operator <(const data &other)const{
		return w < other.w;
	}

	void read(int i){
		scanf("%d%d%d", &u, &v, &w);
		idx = i;
	}
};

bool cmp(data u, data v){
	return u.idx < v.idx;
}

data Edge[N];
data curr[N];
data foo[N];

int n, m;
int lab[N];

int par(int u){
	if(lab[u] < 0) return u;
	return lab[u] = par(lab[u]);
}

bool join(int u, int v){
	u = par(u); v = par(v);
	if(u == v) return false;
	if(lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
	return true;
}

int k;
int ans[N];

struct Quest{
	int idx;
	list < int > lst;
};

Quest start;

int sz = 0;
vector < Quest > elm[N / 2];

int isDead[N];
list < pair < int, int > > changes;

int fakePar(int u){
	if(lab[u] < 0) return u;
	return fakePar(lab[u]);
}

int realPar(int u){
	if(lab[u] < 0) return u;
	isDead[u] = 1;
	changes.emplace_back(u, lab[u]);
	return lab[u] = realPar(lab[u]);
}

bool fakeJoin(int u, int v){
	u = fakePar(u); v = fakePar(v);
	if(u == v) return false;
	isDead[u] = isDead[v] = 1;
	changes.emplace_back(u, lab[u]);
	changes.emplace_back(v, lab[v]);
	if(lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
	return true;
}

void reset(){
	for(auto p : changes){
		if(isDead[p.first] == 0) continue;
		lab[p.first] = p.second;
		isDead[p.first] = 0;
	}
	changes.clear();
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		Edge[i].read(i);
		foo[i] = Edge[i];
	}

	memset(lab, -1, sizeof lab);	

	int q;
	scanf("%d", &q);

	for(int tt = 1; tt <= q; ++tt){
		scanf("%d", &k);
		for(int i = 1; i <= k; ++i){
			int x;
			scanf("%d", &x);
			curr[i] = Edge[x];
		}
		sort(curr + 1, curr + k + 1);



		for(int i = 1; i <= k; ++i){
			int val = curr[i].w;


			int j = i;
			elm[val].push_back(start);
			elm[val][elm[val].size() - 1].idx = tt;
			while(j <= k && curr[j].w == val){
				elm[val][elm[val].size() - 1].lst.push_back(curr[j].idx);
				++j;
			}
			i = j - 1;
		}
		ans[tt] = 1;
	}

	memset(lab, -1, sizeof lab);
	sort(Edge + 1, Edge + m + 1);
	
	for(int i = 1; i <= m;){
		int val = Edge[i].w;
		for(auto &now : elm[val]){
			if(ans[now.idx] == 0) continue;
			for(int idx : now.lst){
				if(!fakeJoin(foo[idx].u, foo[idx].v)){		
					ans[now.idx] = 0;
				}
				else{
					realPar(foo[idx].u);
					realPar(foo[idx].v);
				}
			}
			reset();
		}
		
		while(Edge[i].w == val){
			join(Edge[i].u, Edge[i].v);
			++i;
		}
	}	

	for(int i = 1; i <= q; ++i){
		if(ans[i]) puts("YES");
		else puts("NO");
	}

	return 0;
}