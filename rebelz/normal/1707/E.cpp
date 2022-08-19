// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q;
int a[100005],rmq1[36][18][100005],rmq2[36][18][100005],to[36][100005],lg2[100005];
pii b[36][100005];

int getmin(int i,int l,int r){
	int k=lg2[r-l+1];
	return min(rmq1[i][k][l],rmq1[i][k][r-(1<<k)+1]);
}

int getmax(int i,int l,int r){
	int k=lg2[r-l+1];
	return max(rmq2[i][k][l],rmq2[i][k][r-(1<<k)+1]);
}

pii find(pii now,int i){
	if(now.fi==now.se) return mp(to[i][now.fi],to[i][now.fi]);
	return mp(getmin(i,now.fi,now.se-1),getmax(i,now.fi,now.se-1));
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) to[0][i]=a[i];
	for(int i=1;i<=35;i++) for(int j=1;j<=n;j++) to[i][j]=to[i-1][to[i-1][j]];
	for(int i=1;i<n;i++) b[0][i]=mp(min(a[i],a[i+1]),max(a[i],a[i+1]));
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=35;i++){
		for(int j=1;j<n;j++) rmq1[i-1][0][j]=b[i-1][j].fi,rmq2[i-1][0][j]=b[i-1][j].se;
		for(int j=1;(1<<j)<n;j++){
			for(int k=1;k+(1<<j)-1<n;k++){
				rmq1[i-1][j][k]=min(rmq1[i-1][j-1][k],rmq1[i-1][j-1][k+(1<<(j-1))]);
				rmq2[i-1][j][k]=max(rmq2[i-1][j-1][k],rmq2[i-1][j-1][k+(1<<(j-1))]);
			}
		}
		for(int j=1;j<n;j++){
			if(b[i-1][j].fi==b[i-1][j].se) b[i][j]=mp(to[i-1][b[i-1][j].fi],to[i-1][b[i-1][j].fi]);
			else{
				b[i][j].fi=getmin(i-1,b[i-1][j].fi,b[i-1][j].se-1);
				b[i][j].se=getmax(i-1,b[i-1][j].fi,b[i-1][j].se-1);
			}
		}
	}
	bool fl1=0,fl2=0;
	for(int i=1;i<=n;i++) if(a[i]==1) fl1=1;
	for(int i=1;i<=n;i++) if(a[i]==n) fl2=1;
	pii now;
	while(q--){
		now.fi=readint(),now.se=readint();
		if(now.fi==1&&now.se==n){
			printf("0\n");
			continue;
		}
		if(!fl1||!fl2){
			printf("-1\n");
			continue;
		}
		ll ans=0;
		for(int i=34;i>=0;i--){
			pii tmp=find(now,i);
			if(tmp.fi!=1||tmp.se!=n) now=tmp,ans|=1ll<<i;
		}
		if(ans==(1ll<<35)-1) printf("-1\n");
		else printf("%d\n",ans+1);
	}
	return 0;
}