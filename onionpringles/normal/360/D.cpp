#include <bits/stdc++.h>
using namespace std;
const int N=10101;
int a[N],b[N];
int modpow(int n,int e,int mod){
	if(!e)return 1;
	int t=modpow(n,e/2,mod);
	t=1LL*t*t%mod;
	if(e&1)t=1LL*t*n%mod;
	return t;
}
vector<int> divs;
int main(){
	int n,m,p;scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int bg=0;
	for(int i=0;i<m;i++){
		int x;scanf("%d",&x);bg=__gcd(bg,x);
	}
	
	int i=1;
	for(;i*i<p-1;i++){
		if((p-1)%i==0)divs.push_back(i),divs.push_back((p-1)/i);
	}
	if(i*i==p-1)divs.push_back(i);
	sort(divs.begin(),divs.end());
	
	for(int i=0;i<n;i++){
		int Min=p;
		for(auto &x:divs){
			if(modpow(a[i],x,p)==1)Min=min(Min,x);
		}
		int u=(p-1)/Min;
		int X=1LL*u*bg%(p-1);
		X=__gcd(X,p-1);
		b[i]=X;
	}
	
	int ans=0;
	for(auto &x:divs){
		bool good=false;
		for(int i=0;i<n;i++){
			if(x%b[i]==0){
				good=true;break;
			}
		}
		if(!good)continue;
		int z=(p-1)/x;
		int res=z;
		for(int i=2;i*i<=z;i++){
			if(z%i==0){
				res=res/i*(i-1);
				while(z%i==0)z/=i;
			}
		}
		if(z>1)res=res/z*(z-1);
		ans+=res;
	}
	printf("%d\n",ans);
}