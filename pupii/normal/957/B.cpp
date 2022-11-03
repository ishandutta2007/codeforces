// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[233][233];
int id[51][51];
int x[2501],y[2501];
int fa[2501];
il int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
il int Union(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
vector<int>v[2501];
main(){
	int n=gi(),m=gi();
	for(rg int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(rg int i=1;i<=n;++i)
		for(rg int j=1;j<=m;++j)
			if(s[i][j]=='#')id[i][j]=++id[0][0],x[id[0][0]]=i,y[id[0][0]]=j;
	for(rg int i=1;i<=id[0][0];++i)fa[i]=i;
	for(rg int i=1;i<=n;++i){
		int fst=0;
		for(rg int j=1;j<=m;++j)
			if(s[i][j]=='#')
				if(fst==0)fst=id[i][j];
				else Union(fst,id[i][j]);
	}
	for(rg int j=1;j<=m;++j){
		int fst=0;
		for(rg int i=1;i<=n;++i)
			if(s[i][j]=='#')
				if(fst==0)fst=id[i][j];
				else Union(fst,id[i][j]);
	}
	for(rg int i=1;i<=id[0][0];++i)find(i);
	for(rg int i=1;i<=id[0][0];++i)v[find(i)].push_back(i);
	for(rg int i=1;i<=id[0][0];++i){
		if(v[i].size()==0)continue;
		set<int>X,Y;
		for(rg int j=0;j<v[i].size();++j)
			X.insert(x[v[i][j]]),Y.insert(y[v[i][j]]);
		if(v[i].size()!=X.size()*Y.size()){puts("No");return 0;}
	}
	puts("Yes");
	return 0;
}