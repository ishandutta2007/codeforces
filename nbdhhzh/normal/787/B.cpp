#include<bits/stdc++.h>
using namespace std;
int a[10010],x,i,j,n,m,k;
bool p=0;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d",&k);
		memset(a,0,sizeof a);
		p=0;
		for (j=1;j<=k;j++){
			scanf("%d",&x);
			if(a[abs(x)]==-x)p=1;
			a[abs(x)]=x;
		}
		if(!p)break;
	}
	if(i>m)puts("NO");else puts("YES");
	return 0;
}