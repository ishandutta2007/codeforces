#include <iostream>
using namespace std;
typedef long long ll;
ll n,x,y,c;
inline ll f(ll x){return x*x+2*x+1;}
inline ll g(ll x){return (x+1)*(x+2)/2;}
ll cnt(ll t){
   		   ll ans=2*t*t+t*2+1;
   		   if(t>=x)ans-=f(t-x);
   		   if(t>=y)ans-=f(t-y);
   		   if(t>=n+1-y)ans-=f(t-(n+1-y));
   		   if(t>=n+1-x)ans-=f(t-(n+1-x));
   		   if(t>=x+y)ans+=g(t-(x+y));
   		   if(t>=n+1-x+y)ans+=g(t-(n+1-x+y));
   		   if(t>=n+1-x+n+1-y)ans+=g(t-(n+1-x+n+1-y));
   		   if(t>=x+n+1-y)ans+=g(t-(x+n+1-y));
   		   return ans;
}
int main(){
	cin>>n>>x>>y>>c;
	ll h=-1,t=2*n;
	while(h<t-1){
			   int m=(h+t)/2;
			   ll sum=cnt(m);
			   //cout<<m<<' '<<sum<<endl;
			   if(sum<c)h=m;
			   else t=m;
	}
	cout<<t<<endl;
	//system("pause");
	return 0;
}