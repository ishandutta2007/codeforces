#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;

int main(){
	int T=readint();
	while(T--){
		n=readint();
		if(n&1){
			printf("NO\n");
			continue;
		}
		n>>=1;
		int m=sqrt(n);
		if(m*m==n){
			printf("YES\n");
			continue;
		}
		if(n&1){
			printf("NO\n");
			continue;
		}
		n>>=1;
		m=sqrt(n);
		if(m*m==n){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}