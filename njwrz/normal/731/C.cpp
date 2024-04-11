#include <bits/stdc++.h>
using namespace std;
int f[200005],n,m,k,a[200005];
vector<int> v[200005],ans;
void dfs(int p){
	if(a[p])return;
	a[p]=1;ans.push_back(f[p]);
	for(int i=0;i<v[p].size();i++){
		dfs(v[p][i]);
	}
}
int main(){
	cin>>n>>m>>k;
	int l,r;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=0;i<m;i++){
		cin>>l>>r;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	int shuchu=0;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			ans.clear();
			dfs(i);
			sort(ans.begin(),ans.end());
			int last=ans[0],maxi=1,t=1;
			for(int j=1;j<ans.size();j++){
				if(ans[j]!=last){
					last=ans[j];t=1;
				}else t++;
				maxi=max(maxi,t);
			}
			shuchu+=ans.size()-maxi;
		}
	}
	cout<<shuchu;
	return 0;
}