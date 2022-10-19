#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,a[N],b[N],se[10],nxt[N],ans[N];
char s1[N],s2[N];

void dfs(int x,int y){
	if (x>6){
		nxt[1]=0;
		for (int i=2,j=0;i<=m;++i){
			for (;j&&se[b[j+1]]!=se[b[i]];j=nxt[j]);
			if (se[b[j+1]]==se[b[i]]) nxt[i]=++j;
		}
		for (int i=1,j=0;i<=n;++i){
			for (;j&&se[b[j+1]]!=se[a[i]];j=nxt[j]);
			if (se[b[j+1]]==se[a[i]]) ++j;
			if (j==m){
				ans[i]=min(ans[i],6-y);
				j=nxt[j];
			}
		}
		return;
	}
	for (int i=1;i<=y;++i){se[x]=i; dfs(x+1,y);}
	se[x]=y+1; dfs(x+1,y+1);
}

int main(){
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1); m=strlen(s2+1);
	for (int i=1;i<=n;++i) a[i]=s1[i]-'a'+1;
	for (int i=1;i<=m;++i) b[i]=s2[i]-'a'+1;
	memset(ans,0x3f,sizeof ans);
	dfs(1,0);
	for (int i=m;i<=n;++i) printf(i==n?"%d\n":"%d ",ans[i]);
	
	return 0;
}