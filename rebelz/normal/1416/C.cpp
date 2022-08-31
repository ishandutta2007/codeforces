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

int n,ncnt;
int ch[10000005][2],siz[10000005];
ll a[300005],t[35][2];

void insert(int x){
	int p=0;
	for(int i=30;i>=0;i--){
		if(!ch[p][(x>>i)&1]) ch[p][(x>>i)&1]=++ncnt;
		p=ch[p][(x>>i)&1];
		siz[p]++;
	}
}

void solve(int x){
	int p=0;
	for(int i=30;i>=0;i--){
		if(ch[p][((x>>i)&1)^1]){
			if(x&(1<<i)) t[i][1]+=siz[ch[p][0]];
			else t[i][0]+=siz[ch[p][1]];
		}
		if(!ch[p][(x>>i)&1]) return;
		p=ch[p][(x>>i)&1];
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		solve(a[i]);
		insert(a[i]);
	}
	ll ans=0,now=0;
	for(int i=0;i<=30;i++){
		ans+=min(t[i][0],t[i][1]);
		if(t[i][0]>t[i][1]) now|=1<<i;
	}
	printf("%lld %lld\n",ans,now);
	return 0;
}