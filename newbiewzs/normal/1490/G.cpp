#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;
	int x=1;
	while(c<'0' or c>'9'){
	if(c=='-')x=-1;
	c=getchar();}
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s*x;
}
const int N=2e5+55;
int T,n,m,a[N],x[N];
int s[N];
int cd[N],top,minn[N];
signed main(){
	T=read();
	while(T--){
		n=read();
		m=read();map<long long,int>ma;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=m;i++)x[i]=read();
		top=0;
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
			if(!ma[s[i]])ma[s[i]]=i,cd[++top]=s[i];
		}
		sort(cd+1,cd+top+1);
		minn[top+1]=1e15;
		for(int i=top;i>=1;i--)minn[i]=min(minn[i+1],ma[cd[i]]);
		for(int i=1;i<=m;i++){
			int ans=-1;
			if(s[n]<=0){
				int gg=lower_bound(cd+1,cd+top+1,x[i])-cd;
				if(gg<=top){
					ans=minn[gg];
				}
			}
			else{
				int l=1;int r=x[i]/s[n]+1;
				#define mid ((l+r)>>1)
				while(l<=r){
					bool flag=0;
					int hh=(mid-1)*s[n];
					int gg=lower_bound(cd+1,cd+top+1,x[i]-hh)-cd;
					if(gg<=top){
						flag=1;ans=(mid-1)*n+minn[gg];
					}
					if(!flag)l=mid+1;
					else r=mid-1;
				}
			}
			if(ans!=-1)
			{
				printf("%lld ",ans-1);
			}
			else printf("%d ",-1);
		}
		for(int i=1;i<=top+1;i++)minn[i]=0;
		for(int i=1;i<=top;i++)cd[i]=0;
		for(int i=1;i<=n;i++)s[i]=0;
		puts("");
		ma.clear();
	}
	return 0;
}