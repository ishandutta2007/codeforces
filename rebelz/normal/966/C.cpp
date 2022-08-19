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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt;
ll a[100005],nxt[100005],val[100005];
vector<ll> v[60];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		for(int j=59;j>=0;j--){
			if(a[i]&(1ll<<j)){
				v[j].pb(a[i]);
				break;
			}
		}
	}
	nxt[0]=n+1;
	for(int i=59;i>=0;i--){
		int now=0;
		for(auto r:v[i]){
			if(now>n) return printf("No\n"),0;
			if(!now) nxt[++cnt]=nxt[0],nxt[0]=cnt,val[cnt]=r,now=cnt;
			else{
				while(now<=n&&!(val[now]&(1ll<<i))) now=nxt[now];
				if(now==n+1) return printf("No\n"),0;
				nxt[++cnt]=nxt[now],nxt[now]=cnt,val[cnt]=r,now=cnt;
			}
			now=nxt[now];
		}
	}
	printf("Yes\n");
	for(int i=nxt[0];i<=n;i=nxt[i]) printf("%lld ",val[i]);
	printf("\n");
	return 0;
}