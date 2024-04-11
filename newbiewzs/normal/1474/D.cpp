#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s=0;
	int x=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
const int N=2e5+55;
int T,n,a[N];
int pre[N],suf[N];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		pre[1]=a[1];
		for(int i=2;i<=n;i++){
			pre[i]=a[i]-pre[i-1];
			if(pre[i]<0)pre[i]=1e16;
		}
		suf[n]=a[n];
		for(int i=n-1;i>=1;i--){
			suf[i]=a[i]-suf[i+1];
			if(suf[i]<0)suf[i]=1e16;
		}
		bool flag=0;
		if(pre[n]==0){
			flag=1;
		}
		for(int i=1;i<n;i++){
			if(pre[i-1]>=1e16 || suf[i+2]>=1e16)continue;
			int ii=a[i+1]-pre[i-1];
			if(ii<0)continue;
			int i1=a[i]-ii;
			if(i1<0)continue;
			if(i1==suf[i+2])flag=1;
			if(flag)break;
		}
		if(flag)puts("YES");
		else puts("NO");
		for(int i=1;i<=n;i++)pre[i]=suf[i]=0;
	}
	return 0;
}