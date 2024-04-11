#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[105][105],n,m;
	cin>>n>>m;swap(n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	} 
	vector<int> ans;ans.clear();
	int maxi=0;
	for(int i=1;i<m;i++){
		pair<int,int> p[105];
		for(int j=1;j<=n;j++){
			p[j].first=a[j][i]-a[j][m];p[j].second=j;
		}
		sort(p+1,p+n+1,greater<pair<int,int> >());
		int l=0;vector<int> v;v.clear();
		for(int j=1;j<=n;j++){
			if(l+p[j].first<0){
				break;
			}else{
				v.push_back(p[j].second);l+=p[j].first; 
			}
		}
		if(v.size()>maxi){
			ans=v;
			maxi=v.size();
		}
	}
	bool f[105]={};
	for(int i=0;i<ans.size();i++)f[ans[i]]=1;
	cout<<n-ans.size()<<'\n';
	for(int i=1;i<=n;i++){
		if(f[i]==0)cout<<i<<' ';
	}
	return 0;
}