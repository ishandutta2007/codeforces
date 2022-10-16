#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = ll(1) << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query{
	int l,r,i,k;ll ord;
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
} q[100001];

inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}

int n,m,i,j,k,block,l,r,c[100001],c2[100001],
in[100001],size[100001],ans[100001],color[100001],
cnt[100001];vector<int> v[100001];

void dfs(int x,int p){
	in[x]=++j;
	c[j]=c2[x];
	size[x]=1;
	for (int i=0;i<v[x].size();i++){
		if (v[x][i]!=p){
			dfs(v[x][i],x);
			size[x]+=size[v[x][i]];
		}
	}
}

bool cmp(query a,query b){
	return a.ord<b.ord;
}

void add(int x){
	cnt[++color[c[x]]]++;
}

void sub(int x){
	cnt[color[c[x]]--]--;
}

int main(){
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&c2[i]);
	for (i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	j=0;
	dfs(1,0);
	for (i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].k);
		q[i].r=in[q[i].l]+size[q[i].l]-1;
		q[i].l=in[q[i].l];
		q[i].i=i;
q[i].calcOrder();
	}
	block=sqrt(n)+1;
	sort(q+1,q+m+1);
	l=1;r=0;
	for (i=1;i<=m;i++){
		while (l<q[i].l) sub(l++);
		while (l>q[i].l) add(--l);
		while (r<q[i].r) add(++r);
		while (r>q[i].r) sub(r--);
		ans[q[i].i]=cnt[q[i].k];
	}
	for (i=1;i<=m;i++) printf("%d\n",ans[i]);
}