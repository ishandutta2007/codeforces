#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
#define int long long
const int N=250;
const int M=100050;
int n,m,x[N],y[N],t[N],f[M],cd[M];
signed main(){
//	freopen("ss.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>x[i]>>y[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			vector<int>v[2];
			for(int k=0;k<=m;k++)if(f[k])v[0].push_back(k);
			for(int k=1;k<=y[i];k++){
				v[k&1].clear();
				int pre=((k-1)&1);
				if(!v[pre].size())break;
				for(int j=0;j<v[pre].size();j++){
					int jj=ceil(1.0*v[pre][j]+1.0*x[i]/100000);
					if(jj>m)break;
					if(!f[jj]){
						f[jj]=1;cd[jj]=i;
						v[k&1].push_back(jj);
					}
				}
			}
		}
		else{
			vector<int>v[2];
			for(int k=0;k<=m;k++)if(f[k])v[0].push_back(k);
			for(int k=1;k<=y[i];k++){
				v[k&1].clear();
				int pre=((k-1)&1);
				if(!v[pre].size())break;
				for(int j=0;j<v[pre].size();j++){
					int jj=ceil(1.0*v[pre][j]*x[i]/100000);
					if(jj>m)break;
					if(!f[jj]){
						f[jj]=1;cd[jj]=i;
						v[k&1].push_back(jj);
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!cd[i])printf("-1 ");
		else printf("%d ",cd[i]);
	}
	return 0;
}