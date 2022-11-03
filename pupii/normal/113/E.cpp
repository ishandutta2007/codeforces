#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,s;
ll solve(ll n,ll o){
	--o;if(o<=0)return n;
	while(o--)n/=10;
	return n;
}
ll cnt(ll x){
	ll c=0;
	while(x)c+=(x%10>0),x/=10;
	return c;
}
ll Solve(ll a,ll b){
	ll ret=solve(a,s-cnt(m-1));
	ret+=a*solve(m-1,s);
	ret+=solve(b,s);
	return ret;
}
int main(){
	n=gi(),m=gi(),s=gi();
	int nl=gi(),ml=gi(),nr=gi(),mr=gi();
	if(std::make_pair(nl,ml)>std::make_pair(nr,mr))printf("%lld\n",Solve(n-1,m-1)-Solve(nl,ml)+Solve(nr,mr)+(cnt(n-1)+cnt(m-1)>=s));
	else printf("%lld\n",Solve(nr,mr)-Solve(nl,ml));
	return 0;
}