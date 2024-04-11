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

int n,rt;
ll a[300005],b[300005],lg2[300005],rmq[300005][20],ls[300005],rs[300005],mx[300005],all[300005],ch[300005][2];

int getmin(int l,int r){
	if(l>r) swap(l,r);
	int k=lg2[r-l+1];
	return a[rmq[l][k]]<a[rmq[r-(1<<k)+1][k]]?rmq[l][k]:rmq[r-(1<<k)+1][k];
}

int build(int l,int r){
	int mid=getmin(l,r);
	if(l!=mid) ch[mid][0]=build(l,mid-1);
	if(r!=mid) ch[mid][1]=build(mid+1,r);
	return mid;
}

void dfs(int u){
	if(ch[u][0]) dfs(ch[u][0]);
	if(ch[u][1]) dfs(ch[u][1]);
	ls[u]=max(ls[ch[u][0]],ls[ch[u][0]]+b[u]+mx[ch[u][1]]);
	rs[u]=max(rs[ch[u][1]],rs[ch[u][1]]+b[u]+mx[ch[u][0]]);
	mx[u]=max(mx[ch[u][0]]+mx[ch[u][1]]+b[u],max(mx[ch[u][0]],mx[ch[u][1]]));
	all[u]=ls[ch[u][0]]+b[u]+rs[ch[u][1]];
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<=n;i++) rmq[i][0]=i;
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++) rmq[j][i]=a[rmq[j][i-1]]<a[rmq[j+(1<<(i-1))][i-1]]?rmq[j][i-1]:rmq[j+(1<<(i-1))][i-1];
	rt=build(1,n);
	ls[0]=rs[0]=all[0]=mx[0]=0;
	dfs(rt);
	printf("%lld\n",all[rt]);
	return 0;
}