#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n;

int main(){
	n=readint();
	if(n%2==0) printf("%lld\n",n/2);
	else{
		bool flag=false;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				n-=i; flag=true;
				break;
			}
		}
		if(!flag) printf("1\n");
		else printf("%lld\n",n/2+1);
	}
	return 0;
}