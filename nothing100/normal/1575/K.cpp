#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define mp make_pair
using namespace std;
int n,m,k,res;
const int mo=1000000007;
pair<int,int> a,b,c,d;
int ksm(int x,LL y){
	//printf("%lld\n",y);
	int ans=1;
	while (y){
		if (y&1) ans=1ll*ans*x%mo;
		x=1ll*x*x%mo;
		y=y/2;
	}
	return ans;
}
int main(){
	res=1;
	scanf("%d%d%d%d%d",&n,&m,&k,&c.fi,&c.se);
	scanf("%d%d%d%d",&a.fi,&a.se,&b.fi,&b.se);
	if (a>b) swap(a,b);
	int doit=1;
	while (doit){
		if (a==b){
			res=1ll*res*ksm(k,1ll*n*m);
			break;
		}
		d=mp(0,0);
		if (a.fi+c.fi-1>=b.fi){
			if (a.se<=b.se&&a.se+c.se-1>=b.se){
				d=make_pair(a.fi+c.fi-b.fi,a.se+c.se-b.se);
			}
			else if (a.se>=b.se&&b.se+c.se-1>=a.se){
				d=make_pair(a.fi+c.fi-b.fi,b.se+c.se-a.se);
				b.se=a.se;
				a.se=a.se+c.se-d.se;
			}
		}
		res=1ll*res*ksm(k,1ll*n*m-2ll*c.fi*c.se+1ll*d.fi*d.se)%mo;
		n=c.fi;
		m=c.se;
		c=d;
		if (c.fi==0){
			doit=0;
			res=1ll*res*ksm(k,1ll*n*m)%mo;
		}
	}
	printf("%d\n",res);
}