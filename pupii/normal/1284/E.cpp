#include<bits/stdc++.h>
typedef long long ll;
#define db long double
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct vector{
	db x,y,key;
}s[2510],A[5010];
const db pi=acosl(-1);
ll C3(int n){return 1ll*n*(n-1)*(n-2)/6;}
ll C4(int n){return 1ll*n*(n-1)*(n-2)*(n-3)/24;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();ll ans=0;
	for(int i=1;i<=n;++i)s[i].x=gi(),s[i].y=gi();
	for(int x=1;x<=n;++x){
		ans+=1ll*C4(n-1);
		for(int i=1,j=1;j<=n;++i,++j){
			if(j==x){--i;continue;}
			A[i]={s[j].x-s[x].x,s[j].y-s[x].y,0},A[i].key=atan2l(A[i].y,A[i].x);
		}
		std::sort(A+1,A+n,[](const vector&a,const vector&b){return a.key<b.key;});
		for(int i=1;i<n;++i)A[i+n-1]=A[i],A[i+n-1].key+=2*pi;
		for(int i=1,j=1;i<n;++i){
			while(j<n*2-2&&A[j+1].key-A[i].key<pi)++j;
			ans-=1ll*C3(j-i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}