#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
void exgcd(ll a, ll b, ll& x, ll& y, ll& c)
{
    if(!b){y=0;x=1;c=a;return;}
    exgcd(b,a%b,y,x,c);y-=a/b*x;
}
int main()
{
	ll a,b,x,y,d,n,p,ans1,ans2,ans3;
	scanf("%lld%lld%lld%lld",&n,&p,&a,&b);
	exgcd(a,b,x,y,d);
	if(p%d){
		printf("-1");
		return 0;
	}
	ans1=p/a;
	ans2=0;
	ll last=p%a;
	ans1+=last/d*x;
	ans2+=last/d*y;
	ll min1=a*b/d;
	if(ans2<0){
		ll tot=-ans2/(min1/b);
		if(ans2%(min1/b))tot++;
		ans2+=tot*(min1/b);
		ans1-=tot*(min1/a);
		ans3=n-ans1-ans2;
	}
	else{
		ll tot=ans2/(min1/b);
		ans2-=tot*(min1/b);
		ans1+=tot*(min1/a);
		ans3=n-ans1-ans2;
	}
	if(ans1>=0&&ans2>=0&&ans3>=0)printf("%lld %lld %lld",ans1,ans2,ans3);
	else cout<<"-1";
 }