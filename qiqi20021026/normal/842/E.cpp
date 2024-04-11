#include<bits/stdc++.h>

using namespace std;

#define N 400000

int n,dep[N],len,fa[N][22];
set<int> s1,s2;

int lca(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=20;i>=0;--i)
		if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	for (int i=20;i>=0;--i)
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i]; y=fa[y][i];
		}
	return x==y?x:fa[x][0];
}

int dist(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}


int main(){
	scanf("%d",&n);
	s1.insert(1); dep[1]=1;
	len=0;
	for (int i=1;i<=n;++i){
		int x=i+1;
		scanf("%d",&fa[x][0]);
		dep[x]=dep[fa[x][0]]+1;
		for (int j=1;j<=20;++j) fa[x][j]=fa[fa[x][j-1]][j-1];
		int d1=s1.empty()?0:dist(x,*s1.begin());
		int d2=s2.empty()?0:dist(x,*s2.begin());
		if (max(d1,d2)>len){
			len=max(d1,d2);
			if (d2==len){
				for (set<int>::iterator j=s1.begin();j!=s1.end();++j)
					if (dist(x,*j)==len) s2.insert(*j);
				s1.clear(); s1.insert(x);
			}
			else{
				for (set<int>::iterator j=s2.begin();j!=s2.end();++j)
					if (dist(x,*j)==len) s1.insert(*j);
				s2.clear(); s2.insert(x);
			}
		}
		else
			if (max(d1,d2)==len){
				if (d2==len) s1.insert(x);
				else s2.insert(x);
			}
		printf("%d\n",s1.size()+s2.size());
	}
	
	return 0;
}