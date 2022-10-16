#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5555,mod=1000000007;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,sa[maxn],cnt[maxn],rk[maxn],tmp[maxn],h[maxn],mn[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn],ff[maxn];
char s[maxn];
void rsort(){
	FOR(i,0,m) cnt[i]=0;
	FOR(i,1,n) cnt[rk[tmp[i]]]++;
	FOR(i,1,m) cnt[i]+=cnt[i-1];
	ROF(i,n,1) sa[cnt[rk[tmp[i]]]--]=tmp[i];
}
void build(){
	m=127;
	FOR(i,1,n) rk[i]=s[i],tmp[i]=i;
	rsort();
	for(int d=1,p=1;p<n;m=p,d<<=1){
		p=0;
		FOR(i,1,d) tmp[++p]=n-d+i;
		FOR(i,1,n) if(sa[i]>d) tmp[++p]=sa[i]-d;
		rsort();
		swap(rk,tmp);
		rk[sa[1]]=p=1;
		FOR(i,2,n) rk[sa[i]]=tmp[sa[i]]==tmp[sa[i-1]] && tmp[sa[i]+d]==tmp[sa[i-1]+d]?p:++p;
	}
	int k=0;
	FOR(i,1,n){
		int j=sa[rk[i]-1];
		if(k) k--;
		while(s[i+k]==s[j+k]) k++;
		h[rk[i]]=k;
	}
	FOR(i,1,n){
		mn[i][i]=h[i];
		FOR(j,i+1,n) mn[i][j]=min(mn[i][j-1],h[j]);
	}
}
inline bool cmp(int l1,int r1,int l2,int r2){
	if(r1-l1!=r2-l2) return r1-l1<r2-l2;
	if(l1==l2) return false;
	int x=rk[l1],y=rk[l2];
	if(x>y) swap(x,y);
	int len=mn[x+1][y];
	if(len>=r1-l1+1) return false;
	return s[l1+len]<s[l2+len];
}
void clear(){
	FOR(i,0,n) sa[i]=cnt[i]=rk[i]=tmp[i]=h[i]=0;
	FOR(i,0,n) FOR(j,0,n) f[i][j]=g[i][j]=0;
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	build();
	FOR(i,1,n) FOR(j,1,n) f[i][j]=j==1?1:2e9,g[i][j]=j==1;
	FOR(i,1,n){
		int k=1;
		FOR(j,1,i) if(s[j]=='1'){
			while(k<j && (cmp(j,i,k,j-1) || s[k]!='1')) k++;
			if(k<j){
				f[i][j]=min(f[i][j],f[j-1][k]+1);
				g[i][j]=(g[i][j]+g[j-1][k])%mod;
			}
		}
		if(i==n) FOR(j,1,n) ff[j]=f[i][j];
		ROF(j,i-1,1){
			f[i][j]=min(f[i][j+1],f[i][j]);
			g[i][j]=(g[i][j+1]+g[i][j])%mod;
		}
	}
	int ans=2e9,sum=0,pw=1;
	ROF(i,n,1){
		if(s[i]=='1'){
			sum=(sum+pw)%mod;
			if(ff[i]<=n){
				if(i>=n-20) ans=min(ans,sum+ff[i]);
				else if(ans>1e9){ans=(sum+ff[i])%mod;break;}
			}
		}
		pw=pw*2%mod;
	}
	printf("%d\n%d\n",g[n][1],ans);
	clear();
}
int main(){
//	freopen("ex_print1.in","r",stdin);
//	freopen("print1.out","w",stdout);
	int T=1;
	while(T--) solve();
}