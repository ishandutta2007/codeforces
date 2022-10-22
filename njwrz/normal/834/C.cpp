#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=0; ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();
	}
	if(flag) return X;
	return ~(X-1);
}
map<ll,ll> m;
int main(){
	ll t,s,a,b,n;
	for(ll i=1;i<=1000005;i++)m[i*i*i]=i;
	n=read();
	for(ll k=0;k<n;k++){
		a=read();b=read();
		t=m[a*b];
		if(t==0){
			puts("NO");
		}else if(a%t==0&&b%t==0){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}