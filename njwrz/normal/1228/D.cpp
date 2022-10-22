#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int n,f[100005],q,x[300005],y[300005];
int main(){
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			++q;
			if(q==4){
				cout<<-1;return 0;
			}
			int ff[100005]={0};
			for(int j=0;j<v[i].size();j++){
				ff[v[i][j]]=1;
			}
			for(int j=1;j<=n;j++){
				if(!ff[j]){
					f[j]=q;
				}
			}
		}
	}
	if(q!=3){
		cout<<-1;return 0;
	}
	for(int i=0;i<m;i++){
		if(f[x[i]]==f[y[i]]){
			cout<<-1;return 0;
		}
	}
	int ans[4]={0};
	for(int i=1;i<=n;i++){
		ans[f[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(v[i].size()!=n-ans[f[i]]){
			cout<<-1;return 0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	return 0;
}