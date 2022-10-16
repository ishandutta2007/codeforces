#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,m=128,prv[maxn][26],nxt[maxn][26],at[26],tmp[maxn*18][2],tl;
int cnt[maxn],sa[maxn],rk[maxn],tp[maxn],h[maxn];
int lt[maxn],st[18][maxn],fk[18][maxn],mn[18][maxn],pre[18][maxn];
char s[maxn];
bool ok[18][maxn],tmpok[18][maxn];
ll val[18];
vector<PII> v[18][maxn];
void rsort(){
	FOR(i,0,m) cnt[i]=0;
	FOR(i,1,n) cnt[rk[tp[i]]]++;
	FOR(i,1,m) cnt[i]+=cnt[i-1];
	ROF(i,n,1) sa[cnt[rk[tp[i]]]--]=tp[i];
}
void build(){
	FOR(i,1,n) rk[i]=s[i],tp[i]=i;
	rsort();
	for(int d=1,p=1;p<n;m=p,d<<=1){
		p=0;
		FOR(i,1,d) tp[++p]=n-d+i;
		FOR(i,1,n) if(sa[i]>d) tp[++p]=sa[i]-d;
		rsort();
		swap(rk,tp);
		rk[sa[1]]=p=1;
		FOR(i,2,n) rk[sa[i]]=tp[sa[i]]==tp[sa[i-1]] && tp[sa[i]+d]==tp[sa[i-1]+d]?p:++p;
	}
	FOR(i,1,n) rk[sa[i]]=i;
	int k=0;
	FOR(i,1,n){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		h[rk[i]]=k;
	}
	FOR(i,2,n) lt[i]=lt[i>>1]+1;
	FOR(i,1,n) mn[0][i]=h[i];
	FOR(i,1,lt[n]) FOR(j,1,n-(1<<i)+1) mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
}
inline int lcp(int x,int y){
	x=rk[x];y=rk[y];
	if(x>y) swap(x,y);
	x++;
	int k=lt[y-x+1];
	return min(mn[k][x],mn[k][y-(1<<k)+1]);
}
inline bool check(int i,int j,int k,int mid){
	if(i<mid-(1<<k)+1 || i>mid+(1<<k)-1) return ok[k][mid];
	if(!k) return true;
	return tmpok[k][mid];
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	build();
	FOR(i,1,n){
		FOR(j,0,25) prv[i][j]=at[j];
		at[s[i]-'a']=i;
	}
	FOR(i,0,25) at[i]=n+1; 
	ROF(i,n,1){
		FOR(j,0,25) nxt[i][j]=at[j];
		at[s[i]-'a']=i;
	}
	FOR(i,1,n) ok[0][i]=true;
	FOR(i,1,lt[n]) FOR(j,1,n){
		if(j-(1<<i)+1>=1 && j+(1<<i)-1<=n){
			int l1=j-(1<<i)+1,r1=j-1,l2=j+1,r2=j+(1<<i)-1,len=lcp(l1,l2);
			if(len>=(1<<i)-1){
				if(ok[i-1][(l1+r1)>>1] && ok[i-1][(l2+r2)>>1] && prv[j][s[j]-'a']<l1 && nxt[j][s[j]-'a']>r2) ok[i][j]=true;
			}
			else{
				fk[i][j]=len;
				if(lcp(l1+len+1,l2+len+1)+len+1<(1<<i)-1) fk[i][j]=-1;
				if(~fk[i][j]) v[i][l1+len].PB(MP(l2+len,j)),v[i][l2+len].PB(MP(l1+len,j));
			}
		}
		pre[i][j]=pre[i][j-1]+ok[i][j];
	}
	ll sum=0,ans=0;
	FOR(i,0,lt[n]) val[i]=1ll*((1<<(i+1))-1)*((1<<(i+1))-1);
	FOR(i,0,lt[n]) FOR(j,1,n) if(ok[i][j]) sum+=val[i];
	ans=sum;
	FOR(i,1,n) FOR(j,0,25) if(j+'a'!=s[i]){
		ll tmpsum=sum;
		tl=0;
		FOR(k,1,lt[n]){
			int l1=i-(1<<k)+1,r1=i-1,l2=i+1,r2=i+(1<<k)-1;
			sum-=val[k]*(pre[k][min(n,r2)]-pre[k][max(1,l1)-1]-ok[k][i]);
			if(ok[k][i])
				if((prv[i][j]>=l1 || nxt[i][j]<=r2)) sum-=val[k];
				else{
					tmpok[k][i]=true;
					tmp[++tl][0]=k,tmp[tl][1]=i;
				}
			if(!ok[k][i] && l1>=1 && r2<=n && prv[i][j]<l1 && nxt[i][j]>r2 && lcp(l1,l2)>=(1<<k)-1 && ok[k-1][(l1+r1)>>1] && ok[k-1][(l2+r2)>>1]){
				sum+=val[k];
				tmpok[k][i]=true;
				tmp[++tl][0]=k,tmp[tl][1]=i;
			}
			FOR(l,0,(int)v[k][i].size()-1){
				int x=v[k][i][l].first,mid=v[k][i][l].second;
				int pos1=prv[mid][s[mid]-'a'],pos2=nxt[mid][s[mid]-'a'];
				int l1=mid-(1<<k)+1,r1=mid-1,l2=mid+1,r2=mid+(1<<k)-1;
				if(j+'a'==s[x] && ~fk[k][mid] && j+'a'!=s[mid] && (pos1<l1 || pos1==i && prv[pos1][s[mid]-'a']<l1) && (pos2>r2 || pos2==i && nxt[pos2][s[mid]-'a']>r2) && check(i,j,k-1,(l1+r1)>>1) && check(i,j,k-1,(l2+r2)>>1)){
					tmpok[k][mid]=true;
					tmp[++tl][0]=k,tmp[tl][1]=mid;
					sum+=val[k];
				}
			}
		}
		FOR(j,1,tl) tmpok[tmp[j][0]][tmp[j][1]]=false;
		ans=max(ans,sum);
		sum=tmpsum;
	}
	printf("%lld\n",ans);
}