#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
int a[1000005],maxb[505],minb[505],rmq[1005][12],lg2[1005];
ll d[1005][1005],f[505],k[1005][1005];
vector<int> b[505];

ll mod(ll x){return x>=cys?x-cys:x;}

ll dp(int l,int r){
	if(l>r) return 1;
	if(d[l][r]>=0) return d[l][r];
	int x=k[l][r];
	if(minb[x]<l||maxb[x]>r) return 0;
	ll now1=0,now2=0;
	for(int i=l;i<=minb[x];i++) now1=mod(now1+dp(l,i-1)*dp(i,minb[x]-1)%cys);
	for(int i=maxb[x];i<=r;i++) now2=mod(now2+dp(maxb[x]+1,i)*dp(i+1,r)%cys);
	if(!f[x]){
		f[x]=1;
		for(int i=1;i<b[x].size();i++) f[x]=f[x]*dp(b[x][i-1]+1,b[x][i]-1)%cys;
	}
	d[l][r]=now1*now2%cys*f[x]%cys;
	return d[l][r];
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint();
	m=unique(a+1,a+m+1)-a-1;
	for(int i=2;i<=m;i++) lg2[i]=lg2[i>>1]+1;
	if(m>2*n+1) return printf("0\n"),0;
	for(int i=1;i<=m;i++) rmq[i][0]=a[i];
	for(int i=1;(1<<i)<=m;i++) for(int j=1;j+(1<<i)-1<=m;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j++) k[i][j]=min(rmq[i][lg2[j-i]],rmq[j-(1<<lg2[j-i])+1][lg2[j-i]]);
	memset(minb,0x3f,sizeof(minb));
	for(int i=1;i<=m;i++) minb[a[i]]=min(minb[a[i]],i),maxb[a[i]]=max(maxb[a[i]],i),b[a[i]].push_back(i);
	for(int i=1;i<=n;i++) sort(b[i].begin(),b[i].end());
	memset(d,-1,sizeof(d));
	cout<<dp(1,m)<<endl;
	return 0;
}