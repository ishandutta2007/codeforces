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
const int N=2e5+55;
const int mod=1e9+7;
int T,n,a[N],tou;
signed main(){
	T=read();
	while(T--){
		n=read();
		map<long long,long long>ma;
		tou=0;
		for(int i=1;i<=n;i++)a[i]=read();
		ma[a[1]]=1;
		int zs=1;
		for(int i=2;i<=n;i++){
			tou-=a[i];
			int xj=0;
			if(ma[tou+a[i]])xj=(zs-ma[tou+a[i]]+mod)%mod,ma[tou+a[i]]=zs;
			else ma[tou+a[i]]=zs,xj=zs;
			zs=(zs+xj)%mod;
		}
		printf("%LLd\n",zs);
	}
	return 0;
}