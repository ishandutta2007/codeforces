#include<bits/stdc++.h>

using namespace std;

#define N 300000

int e,s,n,m,x,y,f[3][N];
vector<int> d[3];

int calc(int x,int k){
	int t=lower_bound(d[k].begin(),d[k].end(),x)-d[k].begin();
	return f[k][t]+max(d[k][t]-x-s,0);
}

int main(){
	scanf("%d%d%d%d",&e,&s,&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if (y<e) for (int j=0;j<x;++j) d[j].push_back(y);
	}
	for (int i=0;i<3;++i){
		d[i].push_back(e);
		sort(d[i].begin(),d[i].end());
		n=d[i].size(); --n;
		for (int j=n-1;j>=0;--j)
			f[i][j]=f[i][j+1]+max(d[i][j+1]-d[i][j]-s,0);
	}
	while (m--){
		scanf("%d",&x);
		if (calc(x,0)) puts("-1 -1");
		else printf("%d %d\n",calc(x,1),calc(x,2)-calc(x,1));
	}
	
	return 0;
}