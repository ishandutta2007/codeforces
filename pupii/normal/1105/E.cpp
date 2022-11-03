#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::map<std::string,int>M;
std::string NM;
bool yes[41],s[41][41];
ll f[41];
int a[100010],now,py;
int SR[1048589];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int m=gi()+1,n=gi();
	while(m--){
		int o=m?gi():1;
		if(o==1){
			if(now<=n){
				for(int i=1;i<=now;++i)
					for(int j=i+1;j<=now;++j)
						s[a[i]][a[j]]=s[a[j]][a[i]]=1;
			}else{
				for(int i=1;i<=n;++i)
					for(int j=i+1;j<=n;++j)
						if(yes[i]&&yes[j])s[i][j]=1;
			}
			now=0;memset(yes,0,sizeof yes);
		}else{
			std::cin>>NM;if(!M.count(NM))M[NM]=++py;
			yes[a[++now]=M[NM]]=1;
		}
	}
	int L=n>>1,R=n-L;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(s[i][j])f[i]|=1ll<<j-1;
	for(int i=0;i<1<<R;++i){
		ll SUM=0;
		for(int j=L+1;j<=n;++j)if((i>>j-L-1)&1)SUM|=f[j];
		SUM>>=L;
		if(!(SUM&i))SR[i]=__builtin_popcount(i);
	}
	for(int i=1;i<1<<R;i<<=1)
		for(int j=0;j<1<<R;++j)
			if(~j&i)SR[j|i]=std::max(SR[j|i],SR[j]);
	int ans=0;
	for(int i=0;i<1<<L;++i){
		ll SUM=0;
		for(int j=1;j<=L;++j)if((i>>j-1)&1)SUM|=f[j];
		if(!(SUM&i))ans=std::max(ans,__builtin_popcount(i)+SR[((1<<R)-1)^(SUM>>L)]);
	}
	printf("%d\n",ans);
	return 0;
}