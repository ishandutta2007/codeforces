#include <bits/stdc++.h>
#define m 10000000000
#define ll __int128
using namespace std;
ll f(ll x,ll y){return (x<y)?x*x*(x*x+1)/2+(y-x)*x*(x+1)/2+x*(y*(y-1)*(2*y-1)/6-x*(x-1)*(2*x-1)/6):y*y*(y*y+1)/2-(x-y)*y*(y-1)/2+y*(x*(x+1)*(2*x+1)/6-y*(y+1)*(2*y+1)/6);}
int main(){
	int T,a,b,c,d;
	cin>>T;while(T--){cin>>a>>b>>c>>d;ll r=f(c,d)-f(a-1,d)-f(c,b-1)+f(a-1,b-1);if(r<m){long long ans=r;cout<<ans<<endl;}else{r%=m;string s="";while(r>0)s+=(char)((r%10)+'0'),r/=10;while(s.size()<10)s+='0';reverse(s.begin(),s.end());cout<<"..."<<s<<endl;}}
	return 0;
}