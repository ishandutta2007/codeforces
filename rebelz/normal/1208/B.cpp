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
int a[2005];
map<int,int> now,vis;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int pl=0;
	for(int i=1;i<=n;i++){
		if(now.count(a[i])) chkmax(pl,now[a[i]]);
		chkmax(now[a[i]],i);
	}
	int ans=n-pl;
	for(int i=1;i<=n;i++){
		if(vis.count(a[i])) break;
		vis[a[i]]=1;
		chkmax(pl,now[a[i]]);
		chkmax(ans,i+n-pl);
	}
	printf("%d\n",n-ans);
	return 0;
}