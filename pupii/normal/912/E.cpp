#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const ll inf=1e18;
ll p[17],p1[9],p2[9];
std::vector<ll>s[2];
il vd dfs(int x,ll mul,ll*p,ll&n,std::vector<ll>&s){
	if(x==n+1){s.push_back(mul);return;}
	for(ll a=mul;;a*=p[x]){
		dfs(x+1,a,p,n,s);
		if(a>inf/p[x])break;
	}
}
il ll check(ll x){
	ll ans=0,p=s[1].size()-1;
	for(int i=0;i<s[0].size();++i){
		while(~p&&s[0][i]>x/s[1][p])--p;
		ans+=p+1;
	}
	return ans;
}
int main(){
	ll n=gi(),n1=0,n2=0;
	for(int i=1;i<=n;++i){
		p[i]=gi();
		if(i&1)p1[++n1]=p[i];
		else p2[++n2]=p[i];
	}
	ll k=gi();
	dfs(1,1,p1,n1,s[0]);
	dfs(1,1,p2,n2,s[1]);
	std::sort(s[0].begin(),s[0].end());
	std::sort(s[1].begin(),s[1].end());
	ll l=1,r=1e18,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)>=k)r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}