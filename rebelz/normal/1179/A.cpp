#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q;
int a[100005];
int s[300005];
pii ans[300005];

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int front=0,rear=0;
	for(int i=1;i<=n;i++) s[rear++]=a[i];
	for(int i=1;i<=n;i++){
		ans[i]=mp(s[front],s[front+1]);
		if(s[front]<s[front+1]) s[rear++]=s[front],front++;
		else s[rear++]=s[front+1],s[front+1]=s[front],front++;
	}
	ll x;
	for(int i=1;i<=q;i++){
		x=readint();
		if(x<=n) printf("%d %d\n",ans[x].fi,ans[x].se);
		else printf("%d %d\n",s[front],s[(x-n-1)%(n-1)+front+1]);
	}
	return 0;
}