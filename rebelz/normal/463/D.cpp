#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n,k,tot=0;
int a[10][1005],d[1005],v[1000005],_next[1000005],h[1005],pos[10][1005];

void addedge(int x,int y){v[++tot]=y; _next[tot]=h[x]; h[x]=tot;}

int dfs(int u){
	if(d[u])
		return d[u];
	int now=0;
	for(int p=h[u];p;p=_next[p])
		now=max(now,dfs(v[p])+1);
	return d[u]=now;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			pos[i][a[i][j]]=j;
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			flag=true;
			for(int l=1;l<=k;l++)
				if(pos[l][i]>=pos[l][j])
					flag=false;
			if(flag)
				addedge(i,j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!d[i])
			ans=max(ans,dfs(i));
	cout<<ans+1<<endl;
	return 0;
}