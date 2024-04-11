#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll q,n,m,k;

int main(){
	q=readint();
	while(q--){
		n=readint(); m=readint(); k=readint();
		if(n>m) swap(n,m);
		if(m>k){
			printf("-1\n");
			continue;
		}
		if(n==m){
			if(n%2!=k%2) cout<<k-2<<endl;
			else cout<<k<<endl;
			continue;
		}
		k-=m;
		if((m-n)%2==0&&k%2==1) cout<<m+k-2<<endl;
		else cout<<n+(m-n)/2+(m-n)/2+k<<endl;
	}
	return 0;
}