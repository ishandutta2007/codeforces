#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
int n;
int a[17],d[33000][17][17],cnt[33000],sum[33000],lg2[33000],nxt[33000][17],lab[17];
pii opt[33000][17][17];

void print(int u,int i,int j){
	pii tmp=opt[u][i][j];
	for(int k=0;k<n;k++){
		if(k!=j&&((tmp.fi>>k)&1)){
			printf("%d %d\n",lab[k+1],lab[j+1]);
			for(int l=k+1;l<=n;l++) lab[l]--;
		}
	}
	if(i>1) print(u^tmp.fi,i-1,tmp.se);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=0;i<n;i++) a[i]=readint();
		for(int i=0;i<(1<<n);i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) d[i][j][k]=inf;
		sum[0]=0;
		for(int i=2;i<(1<<n);i++) lg2[i]=lg2[i>>1]+1;
		for(int i=1;i<(1<<n);i++) sum[i]=sum[i^(i&(-i))]+a[lg2[i&(-i)]],cnt[i]=cnt[i>>1]+(i&1);
		for(int i=1;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				nxt[i][j]=-1;
				for(int k=j;k<n;k++){
					if((i>>k)&1){
						nxt[i][j]=k;
						break;
					}
				}
			}
		}
		for(int i=1;i<(1<<n);i++){
			int mina=0;
			for(int j=n-1;j>=0;j--) if((i>>j)&1) mina=j;
			d[i][1][mina]=sum[i],opt[i][1][mina]=mp(i,0);
			for(int j=2;j<=cnt[i];j++){
				for(int l=i;l;l=(l-1)&i){
					for(int k=i^l;k;k&=k-1){
						int lab=lg2[k&(-k)];
						if(nxt[l][lab]>=0&&sum[l]>d[i^l][j-1][lab]&&chkmin(d[i][j][nxt[l][lab]],sum[l])) opt[i][j][nxt[l][lab]]=mp(l,lab);
					}
				}
			}
		}
		int ans=0,opti=0,optj=0;
		for(int i=n;i>=1;i--){
			for(int j=0;j<n;j++){
				if(d[(1<<n)-1][i][j]<inf){
					ans=i,opti=i,optj=j;
					break;
				}
			}
			if(ans) break;
		}
		printf("%d\n",n-ans);
		for(int i=1;i<=n;i++) lab[i]=i;
		print((1<<n)-1,opti,optj);
	}
	return 0;
}