#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,x[5001];
ll f[5001],t[5001];
bool g[5001][5001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i]>>x[i],f[i]=1ll<<60;
	for(int i=0;i<n;i++){
		if(f[i]<=t[i]){
			f[i+1]=min(f[i+1],max(f[i]+abs(x[i+1]-x[i]),t[i]));
			for(int j=i+2;j<=n;j++)
				if(t[i+1]>=max(f[i]+abs(x[j]-x[i]),t[i])+abs(x[i+1]-x[j])) g[i+1][j]=1;
		}
		if(g[i][i+1]&&i+1<n){
			f[i+2]=min(f[i+2],max(t[i]+abs(x[i+2]-x[i]),t[i+1]));
			for(int j=i+3;j<=n;j++)
				if(t[i+2]>=max(t[i]+abs(x[j]-x[i]),t[i+1])+abs(x[i+2]-x[j])) g[i+2][j]=1;
		}
		for(int j=i+2;j<=n;j++)
			if(g[i][j]&&t[i]+abs(x[i+1]-x[i])<=t[i+1]) g[i+1][j]=1;
	}
	puts(f[n]<=t[n]||g[n-1][n]?"YES":"NO");
}