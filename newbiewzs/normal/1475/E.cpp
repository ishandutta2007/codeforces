#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[255555],f[255555];
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int mod=1e9+7;
int c[1050][1050],tong[1080];
void init(){
	c[0][0]=1;
	for(int i=1;i<=1000;i++){
		c[i][0]=c[i][i]=1;
		for(int k=1;k<i;k++){
			c[i][k]=(c[i-1][k-1]+c[i-1][k])%mod;
		}
	}
} 
int cmp(int x,int y){
	return x>y;
}
signed main(){
	cin>>T;
	init();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read(),tong[a[i]]++;
		sort(a+1,a+n+1,cmp);
		int jl;
		for(int i=1;i<=m;i++){
			if(a[i]==a[m]){jl=i;break;}
		}
		int ans=c[tong[a[m]]][m-jl+1];
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)tong[a[i]]--;
	}
	return 0;
}