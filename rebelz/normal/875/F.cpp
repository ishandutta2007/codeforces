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

struct node{
	int x,y,z;
	bool operator<(const node c)const{return z<c.z;}
}e[200005];

int n,m;
int f[200005];
bool fl[200005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint();
	sort(e+1,e+m+1);
	reverse(e+1,e+m+1);
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		if(fx==fy){
			if(!fl[fx]) fl[fx]=1,ans+=e[i].z;
			continue;
		}
		if(fl[fx]&&fl[fy]) continue;
		f[fx]=fy,fl[fy]|=fl[fx],ans+=e[i].z;
	}
	printf("%lld\n",ans);
	return 0;
}