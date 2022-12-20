#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1.5e3+5;
int n,m,b[maxn][maxn];
bool vis[maxn];
int d[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	map<vector<int>,vector<int>> mp;
	for(int i=1;i<=n;i++){
		vector<int> vec(m);
		for(int j=0;j<m;j++) vec[j]=read();
		mp[vec].push_back(i);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=read();
	for(int i=n;i>0;i--){
		vector<int> vec(b[i]+1,b[i]+m+1);
		if(!mp[vec].size()){
			printf("-1\n");
			return 0;
		}
		b[i][m+1]=mp[vec].back();
		mp[vec].pop_back();
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m+1;j++) d[j]+=b[i][j]>b[i+1][j];
	vector<int> ans;
	for(int i=1;i<=m+1;i++) if(!d[i]) ans.push_back(i);
	for(int i=0;i<(int)ans.size();i++){
		int x=ans[i];
		if(x>m){
			ans.resize(i);
			break;
		}
		for(int j=1;j<n;j++) if(!vis[j]&&b[j][x]<b[j+1][x]){
			vis[j]=1;
			for(int k=1;k<=m+1;k++)
				if(b[j][k]>b[j+1][k]&&!--d[k]) ans.push_back(k);
		}
	}
	if(!d[m+1]){
		reverse(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size());
		for(int i:ans) printf("%d ",i);
	}
	else printf("-1\n");
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}