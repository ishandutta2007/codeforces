#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,sum;
bool flag;

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		if(n<=31&&(1ll<<n+n)<3*k+1){printf("NO\n");continue;}
		flag=true;
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=1;j<=i;j++) sum+=(1ll<<j)-1;
			if(sum>k) break;
			if(n>31||k*3<=((1ll<<n+n-i-i)*((1ll<<i)-1)*((1ll<<i)-1)+(1ll<<(i+1))-2)){
				flag=false; printf("YES %lld\n",n-i);
				break;
			}
		}
		if(flag) printf("NO\n");
	}
	return 0;
}