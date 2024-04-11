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
ll a[100005],s[100005],ans[100005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint(),s[i]=s[i-1]+a[i];
	if(s[m]<n) return printf("-1\n"),0;
	for(int i=1;i<=m;i++) if(a[i]>n-i+1) return printf("-1\n"),0;
	ans[m+1]=n+1;
	for(int i=m;i>=1;i--) ans[i]=min(s[i-1]+1,min((ll)ans[i+1]-1,(ll)n-a[i]+1));
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}