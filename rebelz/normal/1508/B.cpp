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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k;
bool vis[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		if(n<=61&&k>(1ll<<(n-1))){
			printf("-1\n");
			continue;
		}
		k--;
		vis[n]=1;
		for(int i=1;i<n;i++){
			if(n-i-1<=60&&k>=(1ll<<(n-i-1))){
				k-=1ll<<(n-i-1);
				vis[i]=0;
			}
			else vis[i]=1;
		}
		vis[0]=1;
		for(int i=0;i<n;i++){
			if(!vis[i]) continue;
			int pl=i+1;
			while(pl<=n&&!vis[pl]) pl++;
			for(int j=pl;j>=i+1;j--) printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}