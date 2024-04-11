#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct edge{int a,b,c;}s[500010];
il bool operator<(const edge&a,const edge&b){return a.c<b.c;}
int A[500010],B[500010],C[500010];
std::vector<std::vector<int> >QAQ[500010];
std::vector<int>sQ[500010];
bool ans[500010];
int fa[500010],siz[500010];
il int hd(int x){while(fa[x]^x)x=fa[x];return x;}
std::stack<std::pair<int*,int> >stk;
il int Union(int x,int y){
	x=hd(x),y=hd(y);
	if(x==y)return 0;
	if(siz[x]>siz[y])stk.push(std::make_pair(&siz[x],siz[x])),stk.push(std::make_pair(&fa[y],fa[y])),siz[x]+=siz[y],fa[y]=x;
	else stk.push(std::make_pair(&siz[y],siz[y])),stk.push(std::make_pair(&fa[x],fa[x])),siz[y]+=siz[x],fa[x]=y;
	return 2;
}
il vd Undo(int step){while(step--)*stk.top().first=stk.top().second,stk.pop();}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i)A[i]=s[i].a=gi(),B[i]=s[i].b=gi(),C[i]=s[i].c=gi();
	int Q=gi();
	for(int i=1;i<=Q;++i){
		int k=gi(),a;ans[i]=1;
		while(k--){
			a=gi();
			if(sQ[C[a]].empty()||sQ[C[a]].back()!=i)sQ[C[a]].push_back(i),QAQ[C[a]].push_back(std::vector<int>());
			QAQ[C[a]].back().push_back(a);
		}
	}
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	std::sort(s+1,s+m+1);
	for(int i=1,p=1;i<=500000;++i){
		for(int j=0;j<sQ[i].size();++j){
			if(!ans[sQ[i][j]])continue;
			int sum=0,r;
			for(int k=0;k<QAQ[i][j].size();++k){
				r=Union(A[QAQ[i][j][k]],B[QAQ[i][j][k]]);
				if(r)sum+=r;
				else{ans[sQ[i][j]]=0;break;}
			}
			Undo(sum);
		}
		while(p<=m&&s[p].c==i)Union(s[p].a,s[p].b),++p;
	}
	for(int i=1;i<=Q;++i)puts(ans[i]?"YES":"NO");
	return 0;
}