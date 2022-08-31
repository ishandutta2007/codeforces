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
ll x[100005],y[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
	if(n&1) return printf("NO\n"),0;
	int t1=1,t2=n/2+1;
	bool fl=1;
	for(int i=2;i<=n/2;i++){
		if((y[i]-y[t1])*(x[i+n/2]-x[t2])!=(y[i+n/2]-y[t2])*(x[i]-x[t1])
		||(y[i]-y[t2])*(x[i+n/2]-x[t1])!=(y[i+n/2]-y[t1])*(x[i]-x[t2])) fl=0;
	}
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}