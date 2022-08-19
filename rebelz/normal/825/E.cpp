#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<set>

using namespace std;

set<int> s;
int n,m,tot=0;
int v[200005],nxt[200005],h[100005],du[100005],ans[100005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(y,x);
		du[x]++;
	}
	for(int i=1;i<=n;i++)
		if(du[i]==0)
			s.insert(i);
	set<int>::iterator it;
	int u;
	for(int i=n;i>=1;i--){
		it=s.end(); it--; u=*it;
		s.erase(it); ans[u]=i;
		for(int p=h[u];p;p=nxt[p])
			if((--du[v[p]])==0)
				s.insert(v[p]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}