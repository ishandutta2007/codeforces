#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>s[100010];
int L[100010],R[100010],m;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),le;
	ll ans=1ll*n*n;
	for(int i=1;i<=n;++i){
		bool y=1;
		le=gi();
		while(le--)s[i].push_back(gi());
		for(int j=1;j<s[i].size();++j)y&=s[i][j-1]>=s[i][j];
		if(y)L[++m]=s[i][0],R[m]=s[i].back();
	}
	std::sort(L+1,L+m+1);
	std::sort(R+1,R+m+1);
	for(int i=1,p=0;i<=m;++i){
		while(p<m&&L[p+1]<=R[i])++p;
		ans-=p;
	}
	printf("%lld\n",ans);
	return 0;
}