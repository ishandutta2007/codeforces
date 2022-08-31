#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[300005],nxt[300005],d[300005];
map<int,int> b[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n+1;i++) b[i].clear(),nxt[i]=-1,d[i]=0;
		ll ans=0;
		for(int i=n;i>=1;i--){
			if(b[i+1].count(a[i])){
				nxt[i]=b[i+1][a[i]];
				swap(b[i],b[nxt[i]+1]);
				d[i]=d[nxt[i]+1]+1;
				ans+=d[i];
			}
			b[i][a[i]]=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}