#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	int x=1;
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
const int N=2e3+55;
int T,n,a[N];
int vis[N];
vector<int>v[1005000];
int stx[N],sty[N],top;
signed main(){
	T=read();
	while(T--){
		n=read();n*=2;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			v[a[i]].push_back(i);
		}
		bool flag=0;
		int jl;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<n;i++){
			int sum=a[n]+a[i];
			vis[n]=vis[i]=1;
			jl=i;
			top=0;
			stx[++top]=n;
			sty[top]=i;
			bool bj=0;
			int qz=a[n];
			for(int k=n-1;k>=1;k--){
				if(vis[k])continue;
				if(qz<a[k]){
					bj=1;
					break;
				}
				v[a[k]].pop_back();
				vis[k]=1;
				while(v[qz-a[k]].size() and vis[v[qz-a[k]].back()])
				{
					v[qz-a[k]].pop_back();
				}
				if(!v[qz-a[k]].size()){
					bj=1;
					break;
				}
				vis[v[qz-a[k]].back()]=1;
				stx[++top]=k;
				sty[top]=v[qz-a[k]].back();
				v[qz-a[k]].pop_back();
				qz=a[k];
			}
			if(!bj)
			{
				flag=1;
				break;
			}
			for(int k=1;k<=n;k++){
				vis[k]=0;
				vector<int>().swap(v[a[k]]);
			}
			for(int k=1;k<=n;k++){
				v[a[k]].push_back(k);
			}
		}
		for(int i=1;i<=n;i++){
			vector<int>().swap(v[a[i]]);
		}
		if(flag)
		{
			puts("YES");
			printf("%lld\n",a[jl]+a[n]);
			for(int i=1;i<=n/2;i++){
				printf("%lld %lld\n",a[sty[i]],a[stx[i]]);
			}
		}
		else puts("NO");
	}
	return 0;
}