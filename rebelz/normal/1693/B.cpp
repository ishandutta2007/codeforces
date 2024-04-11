// xtqqwq
#include<bits/stdc++.h>

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
int f[200005];
ll a[200005],l[200005],r[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=2;i<=n;i++) f[i]=readint();
		for(int i=1;i<=n;i++) l[i]=readint(),r[i]=readint();
		for(int i=1;i<=n;i++) a[i]=0;
		int ans=0;
		for(int i=n;i>=1;i--){
			if(a[i]<l[i]) ans++,a[f[i]]+=r[i];
			else a[f[i]]+=min(a[i],r[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}