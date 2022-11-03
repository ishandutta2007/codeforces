#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int s[10000010];
int A[1000010];
ll ans=5e18;int ans1,ans2;
il vd chkans(ll ass,int a,int b){if(ans>ass)ans=ass,ans1=a,ans2=b;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();A[0]=1e9;
	for(int i=1;i<=n;++i){
		A[i]=gi();
		if(s[A[i]])chkans(A[i],s[A[i]],i);
		else s[A[i]]=i;
	}
	for(int i=1;i<=10000000&&i<=ans;++i){
		std::pair<int,int>p(0,0);
		for(int j=i;j<=10000000;j+=i)
			if(s[j]){
				if(!p.first)p.first=s[j];
				else{
					p.second=s[j];
					chkans(1ll*A[p.first]/i*A[p.second],p.first,p.second);
					break;
				}
			}
	}
	if(ans1>ans2)std::swap(ans1,ans2);printf("%d %d\n",ans1,ans2);
	return 0;
}