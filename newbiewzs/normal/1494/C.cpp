#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int s=0;
	int x=1;
	while(c<'0' or c>'9')
	{
	if(c=='-')x=-1;
	c=getchar();
	}
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();
	return s*x;
} 
int T,n,m;
const int N=4e5+55;
int a[N],b[N];
int qz[N],hz[N];
int st[N];
int main()
{
	T=read();
	while(T--){
		n=read();m=read();
		map<int,int>ma,pi;
		for(int i=1;i<=n;i++){
			a[i]=read();
			pi[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			b[i]=read();
			ma[b[i]]=i;
		}
		int jl=-1;
		for(int i=1;i<=n;i++){
			if(a[i]<0 and a[i+1]>=0){
				jl=i;break;
			}
		}
		if(jl==-1){
			jl=0;
		}
		int ans=0;
		int top=0;
		for(int i=1;i<=m;i++){
			qz[i]=qz[i-1];
			if(pi[b[i]])qz[i]++;
			if(b[i]<0)top=i;
		}
		if(top){
			for(int i=1;i<=m;i++){
				if(b[i]>0)break;
				int gg=lower_bound(a+1,a+jl+1,b[i])-a;
				int zs=(jl-gg+1);
				int zuo=b[i]-zs+1;
				int you=b[i]+zs-1;
				int y=upper_bound(b+1,b+top+1,you)-b-1;
				int z=lower_bound(b+1,b+top+1,zuo)-b;
				ans=max(ans,max(y-i+1+qz[i-1],i-z+1));
			}
		}
		top=m+1;
		int lj=ans;
		ans=0;
		for(int i=m;i>=1;i--){
			hz[i]=hz[i+1];
			if(pi[b[i]])hz[i]++;
			if(b[i]>0)top=i;
		}
		if(top<=m and jl<n){
			for(int i=m;i>=1;i--){
				if(b[i]<0)break;
				int gg=upper_bound(a+jl+1,a+n+1,b[i])-a-1;
				int zs=(gg-jl);
				int zuo=b[i]-zs+1;
				int you=b[i]+zs-1;
				int y=upper_bound(b+top,b+m+1,you)-b-1;
				int z=lower_bound(b+top,b+m+1,zuo)-b;
				ans=max(ans,max(y-i+1,i-z+1+hz[i+1]));
			}
		}
		for(int i=1;i<=(max(n,m));i++){
			hz[i]=qz[i]=0;
			a[i]=b[i]=0;
		}
		printf("%d\n",lj+ans);
		ma.clear(); 
	}
	return 0;
}