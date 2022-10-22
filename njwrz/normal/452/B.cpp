#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n,m;bool f[20];
pair<int,int> ans[5],tt[5];
vector<pair<int,int> > a; 
double maxi;
void dfs(int p){
	if(p==4){
		double t=0;
		for(int i=1;i<4;i++){
			double t1=(double)(abs(tt[i].first-tt[i-1].first));
			double t2=(double)(abs(tt[i].second-tt[i-1].second));
			t1=t1*t1;
			t2=t2*t2;
			t=t+sqrt(t1+t2);
		}
		if(t>maxi){
			maxi=t;
			for(int i=0;i<4;i++)ans[i]=tt[i];
		}
		return;
	}
	for(int i=0;i<a.size();i++)if(f[i]==0){f[i]=1;tt[p]=a[i];dfs(p+1);f[i]=0;}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if((i<2||n-i<2)&&(j<2||m-j<2))a.push_back(make_pair(i,j));
		}
	}
	dfs(0);
	for(int i=0;i<4;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}