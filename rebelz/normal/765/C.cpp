#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int k,a,b;

int main(){
	k=readint(); a=readint(); b=readint();
	if(a<k&&b<k) return printf("-1\n"),0;
	if(a<k){
		if(b%k==0) return printf("%d\n",b/k),0;
		else printf("-1\n"),0;
	}
	else if(b<k){
		if(a%k==0) return printf("%d\n",a/k),0;
		else printf("-1\n"),0;
	}
	else{
		printf("%d\n",a/k+b/k);
	}
	return 0;
}