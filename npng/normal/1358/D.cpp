#include <cstdio>
#include <iostream>
using namespace std;
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=400000;
typedef long long ll;
ll a[Maxn+5];
ll sum[Maxn+5],tmp[Maxn+5];
ll x;
int n;
int main(){
	read(n),read(x);
	for(int i=1;i<=n;i++){
		read(a[i]);
		a[i+n]=a[i];
	}
	n<<=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		tmp[i]=tmp[i-1]+a[i]*(a[i]+1)/2;
	}
	ll m=1,d=1;
	ll ans=1;
	for(int i=1;i<=n;i++){
		while(sum[i]-sum[m]+a[m]-d+1>x){
			if(sum[i]-sum[m]<x){
				d=a[m]-(x-(sum[i]-sum[m]))+1;
			}
			else{
				m++;
				d=1;
			}
		}
		ans=max(ans,tmp[i]-tmp[m]+(d+a[m])*(a[m]-d+1)/2);
	}
	cout<<ans<<endl;
	return 0;
}