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

int n,q;
int a[200005],pl[200005],maxa[200005],f[200005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) chkmax(pl[a[i]],i),maxa[a[i]]++;
	for(int i=1;i<=200000;i++) f[i]=i;
	int now=0,rg=0,ans=n;
	for(int i=1;i<=n;i++){
		if(now){
			int fx=getf(a[i]);
			if(fx==now){
				if(rg==i) ans-=maxa[now],now=0;
				continue;
			}
			f[fx]=now;
			chkmax(maxa[now],maxa[a[i]]);
			chkmax(rg,pl[a[i]]);
		}
		else{
			now=a[i];
			rg=pl[a[i]];
		}
		if(rg==i) ans-=maxa[now],now=0;
	}
	printf("%d\n",ans);
	return 0;
}