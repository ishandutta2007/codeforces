#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 120000

LL n,m,op,x,y,z,a[N],fa[N],num[N],sum[N];
bool vis[N];
multiset<LL> se[N],tmp;

LL cnt(LL x){return a[x]/(num[x]+2);}

LL slf(LL x){return a[x]-a[x]/(num[x]+2)*(num[x]+1);}

LL son(LL x){return sum[x]+slf(x);}

void ins(LL x){
	if (!vis[x]&&!se[x].empty()){
		vis[x]=1;
		tmp.insert(*se[x].begin()+cnt(x));
		tmp.insert(*se[x].rbegin()+cnt(x));
	}
}

void rmv(LL x){
	if (!vis[x]&&!se[x].empty()){
		vis[x]=1;
		tmp.erase(tmp.find(*se[x].begin()+cnt(x)));
		tmp.erase(tmp.find(*se[x].rbegin()+cnt(x)));
	}
}

void add(int x){
	if (!vis[x]){
		vis[x]=1;
		se[fa[x]].insert(son(x));
	}
}

void del(int x){
	if (!vis[x]){
		vis[x]=1;
		se[fa[x]].erase(se[fa[x]].find(son(x)));
	}
}

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i) scanf("%lld",&a[i]);
	for (LL i=1;i<=n;++i){scanf("%lld",&fa[i]); ++num[fa[i]];}
	for (LL i=1;i<=n;++i) sum[fa[i]]+=cnt(i);
	for (LL i=1;i<=n;++i){add(i); vis[i]=0;}
	for (LL i=1;i<=n;++i){ins(i); vis[i]=0;}
	while (m--){
		scanf("%lld",&op);
		if (op==1){
			scanf("%lld%lld",&x,&y); z=fa[x];
			rmv(z); rmv(fa[z]); rmv(fa[fa[z]]); rmv(y); rmv(fa[y]); rmv(fa[fa[y]]);
			vis[z]=vis[fa[z]]=vis[fa[fa[z]]]=vis[y]=vis[fa[y]]=vis[fa[fa[y]]]=0;
			del(x); del(z); del(fa[z]); del(y); del(fa[y]);
			vis[x]=vis[z]=vis[fa[z]]=vis[y]=vis[fa[y]]=0;
			sum[z]-=cnt(x);
			sum[fa[y]]-=cnt(y);
			sum[fa[z]]-=cnt(z);
			++num[y];
			fa[x]=y;
			--num[z];
			sum[y]+=cnt(x);
			sum[fa[y]]+=cnt(y);
			sum[fa[z]]+=cnt(z);
			add(x); add(z); add(fa[z]); add(y); add(fa[y]);
			vis[x]=vis[z]=vis[fa[z]]=vis[y]=vis[fa[y]]=0;
			ins(z); ins(fa[z]); ins(fa[fa[z]]); ins(y); ins(fa[y]); ins(fa[fa[y]]);
			vis[z]=vis[fa[z]]=vis[fa[fa[z]]]=vis[y]=vis[fa[y]]=vis[fa[fa[y]]]=0;
		}
		if (op==2){
			scanf("%lld",&x);
			printf("%lld\n",son(x)+cnt(fa[x]));
		}
		if (op==3){
			printf("%lld %lld\n",*tmp.begin(),*tmp.rbegin());
		}
	}
	
	return 0;
}