#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t,n,m,xx1,xx2,xx3,xx4,yy1,yy2,yy3,yy4,w,b;

ll cw(ll x,ll y,ll t){
	if(x%2==1&&y%2==1){
		if(t==0)
			return x*y/2+1;
		else
			return x*y/2;
	}
	else
		return x*y/2;
}

ll cb(ll x,ll y,ll t){
	if(x%2==1&&y%2==1){
		if(t==0)
			return x*y/2;
		else
			return x*y/2+1;
	}
	else
		return x*y/2;
}

int main(){
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&xx1,&yy1,&xx2,&yy2,&xx3,&yy3,&xx4,&yy4);
		
		if(n%2==1&&m%2==1)
			w=n*m/2+1,b=n*m/2;
		else
			w=n*m/2,b=n*m/2;
		ll tb=cb(xx2-xx1+1,yy2-yy1+1,(xx1+yy1)%2);
		w+=tb,b-=tb;
//		cout<<"TEST "<<w<<' '<<b<<endl;
		ll tw=cw(xx4-xx3+1,yy4-yy3+1,(xx3+yy3)%2);
		b+=tw,w-=tw;
//		cout<<"TEST "<<w<<' '<<b<<endl;
		ll lx=max(xx1,xx3),rx=min(xx2,xx4);
		ll ly=max(yy1,yy3),ry=min(yy2,yy4);
		if(lx<=rx&&ly<=ry){
			ll kw=cw(rx-lx+1,ry-ly+1,(lx+ly)%2),kb=cb(rx-lx+1,ry-ly+1,(lx+ly)%2);
			w-=kb,b+=kb;
		}
		printf("%lld %lld\n",w,b);
	}
	return 0;
}