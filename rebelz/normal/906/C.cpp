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

int n,m,tot;
int v[10005],nxt[10005],h[30],to[30],lg2[4200000],d[4200000],cnt[4200000];
bool can[4200000];
pii opt[4200000];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void print(int id){
	if(!d[id]) return;
	print(opt[id].fi);
	printf("%d ",opt[id].se);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	for(int i=2;i<=(1<<n);i++) lg2[i]=lg2[i>>1]+1;
	for(int i=0;i<n;i++) can[1<<i]=1;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<(1<<n);i++){
		cnt[i]=cnt[i>>1]+(i&1);
		if(can[i]) continue;
		if(!can[i-(i&(-i))]) continue;
		int now=0;
		for(int p=h[lg2[i&(-i)]+1];p;p=nxt[p]) if(i&(1<<(v[p]-1))) now++;
		if(now==cnt[i]-1) can[i]=1;
	}
	for(int i=0;i<(1<<n);i++) if(can[i]) d[i]=0;
	for(int i=1;i<=n;i++) for(int p=h[i];p;p=nxt[p]) to[i]|=1<<(v[p]-1);
	for(int i=1;i<(1<<n);i++){
		if(d[i]==0x3f3f3f3f) continue;
		for(int j=1;j<=n;j++)
			if((i>>(j-1))&1)
				if(chkmin(d[i|to[j]],d[i]+1)) opt[i|to[j]]=mp(i,j);
	}
	printf("%d\n",d[(1<<n)-1]);
	print((1<<n)-1);
	printf("\n");
	return 0;
}