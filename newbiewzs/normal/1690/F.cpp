#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int T,n,k,a[N],tong[N],p[N],st[N],vis[N],top;
char c[N],s[N];
int read(){
	
}
void dfs(int u){
	vis[u]=1;
	st[++top]=s[u]-'a';
	if(!vis[p[u]])dfs(p[u]);
}
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
signed main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		int ans=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				top=0;
				dfs(i);
				for(int k=1;k<=top;k++){
					bool flag=0;
					if(top%k)flag=1;
					for(int j=1;j<=k;j++){
						int tmp=st[j];
						for(int h=j;h<=top;h+=k){
							if(st[h]!=tmp)flag=1;
						}
					}
					if(!flag){
						ans=lcm(ans,k);
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)vis[i]=0;
	}
	return 0;
}