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

int n;
int a[1000005];
pii d[2100000];

void update(int x,pii y){
	if(y.fi>d[x].fi) d[x].se=d[x].fi,d[x].fi=y.fi;
	else chkmax(d[x].se,y.fi);
	chkmax(d[x].se,y.se);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),update(a[i],mp(i,0));
	for(int i=0;i<21;i++) for(int j=0;j<(1<<21);j++) if(j&(1<<i)) update(j^(1<<i),d[j]);
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=20;j>=0;j--){
			if(a[i]&(1<<j)) continue;
			if(d[now^(1<<j)].se>i) now^=(1<<j);
		}
		if(d[now].se>i) chkmax(ans,a[i]|now);
	}
	printf("%d\n",ans);
	return 0;
}