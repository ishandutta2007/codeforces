#include <bits/stdc++.h>
using namespace std;
vector <int> a[100005];
int p[100005],n,m,ans,f[100005];
void dfs(int jd,int lm){
	f[jd]=1;
	int ansf=1;
	if(p[jd])lm++;else lm=0;
	if(lm>m)return ;
	for(int i=0;i<a[jd].size();i++){
		if(f[a[jd][i]]==0){
			ansf=0;
			dfs(a[jd][i],lm);
		}
	}
	if(ansf){
		ans++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>p[i];
	int x,y;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}