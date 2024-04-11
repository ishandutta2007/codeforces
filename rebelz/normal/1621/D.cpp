// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

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
		int mina=1<<30;
		ll res=0;
		for(int i=1;i<=n+n;i++){
			for(int j=1;j<=n+n;j++){
				int x=readint();
				if(i==1){
					if(j==n+1||j==n+n) chkmin(mina,x);
				}
				else if(i==n){
					if(j==n+1||j==n+n) chkmin(mina,x);
				}
				else if(i==n+1){
					if(j==1||j==n) chkmin(mina,x);
				}
				else if(i==n+n){
					if(j==1||j==n) chkmin(mina,x);
				}
				if(i>n&&j>n) res+=x;
			}
		}
		printf("%lld\n",res+mina);
	}
	return 0;
}