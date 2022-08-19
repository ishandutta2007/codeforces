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

int n,m;
int a[4200000],f[4200000],tag[4200000],pl[4200000],siz[4200000];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx!=fy) f[fx]=fy;
}

void addtag(int x,int t){
	if(tag[x]&&siz[x]) merge(tag[x],t);
	tag[x]=t;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint(),siz[a[i]]=1;
	for(int i=1;i<=m;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		pl[a[i]]=i;
		addtag(((1<<n)-1)^a[i],i);
	}
	for(int i=0;i<n;i++) for(int j=1;j<(1<<n);j++) if(j&(1<<i)) siz[j]+=siz[j^(1<<i)];
	for(int i=(1<<n)-1;i>=1;i--){
		if(!tag[i]||!siz[i]) continue;
		if(pl[i]) merge(pl[i],tag[i]);
		for(int j=0;j<n;j++) if((i>>j)&1) addtag(i^(1<<j),tag[i]);
	}
	int ans=0;
	for(int i=1;i<=m;i++) if(getf(i)==i) ans++;
	printf("%d\n",ans);
	return 0;
}