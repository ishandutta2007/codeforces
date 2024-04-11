#include <stdio.h>
#include <algorithm>
#define MA 1000000
typedef long long LL;

LL n,m,lim;
LL b[MA+5];
LL k,gnm,lnm;
int p1[MA+5],p2[MA+5];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void exgcd(LL &x,LL &y,LL a,LL b){
    if(!b){
        x=1;
        y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    LL t=x;
    x=y;
    y=t-a/b*y;
}

bool check(LL day){
	LL tot = day;
	for(int i=1;i<=lim;i++){
		if(b[i]==-1||day<b[i]) continue;
		tot -= (day-b[i])/lnm+1;
	}
	return tot>=k;
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	lim = std::max(n,m)*2;
	gnm = gcd(n,m);
	lnm = n/gnm*m;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		p1[a] = i;
	}
	for(int i=1;i<=m;i++){
		int b;
		scanf("%d",&b);
		p2[b] = i;
	}
	LL bx,by,mod=m/gnm;
	exgcd(bx,by,n,m);
	for(int i=1;i<=lim;i++){
		if(p1[i]&&p2[i]&&p1[i]%gnm==p2[i]%gnm){
			//xn+p1[i] = ym+p2[i]
			LL d = p2[i]-p1[i];
			LL r = d/gnm;
			LL x = bx*r;
			x = (x%mod+mod)%mod;
			b[i] = x*n+p1[i];
		}else{
			b[i] = -1;
		}
	}
	LL l=0,r=1e18,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	printf("%lld\n",l);
}