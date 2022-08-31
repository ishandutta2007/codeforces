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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[200005],lg2[200005],rmq[200005][20],ans[200005];

int qmin(int l,int r){
	int k=lg2[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}

int getans(int l,int r,int x){
	if(qmin(l,r)>=x) return 1<<30;
	int ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(qmin(l,mid)<x) ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}

int main(){
	n=readint();
	int mx=0,mn=1<<30;
	for(int i=1;i<=n;i++) a[i]=readint(),chkmax(mx,a[i]),chkmin(mn,a[i]);
	for(int i=2;i<=n+n;i++) lg2[i]=lg2[i>>1]+1;
	if(mx/2.0<=mn){
		for(int i=1;i<=n;i++) printf("-1 ");
		printf("\n");
		return 0;
	}
	for(int i=1;i<=n;i++) a[i+n]=a[i];
	for(int i=1;i<=n+n;i++) rmq[i][0]=a[i];
	for(int i=1;i<=19;i++) for(int j=1;j+(1<<i)-1<=n+n;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	int now=1; mx=a[n];
	while(1){
		if(a[now]<mx/2.0) break;
		chkmax(mx,a[now]);
		now++;
	}
	int r=n+now; ans[n]=now;
	for(int i=n-1;i>=1;i--){
		chkmin(r,getans(i+1,n+n,(a[i]+1)/2));
		ans[i]=r-i;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}