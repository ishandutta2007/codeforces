#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
struct wtf{
	int l,c,s;
	wtf(int l_=0,int c_=-1,int s_=0):l(l_),c(c_),s(s_){}
	bool operator<(const wtf &w)const{return l<w.l;}
}f[52][1111];
int n,l[11],id[11][maxn],at[11][52][2];
char str[11][maxn];
PII pr[52][1111];
void clear(){
	FOR(i,0,51) FOR(j,0,(1<<n)-1) f[i][j]=(wtf){0,-1,0},pr[i][j]=MP(0,0);
	FOR(i,0,n-1){
		FOR(j,1,l[i]) id[i][j]=0;
		FOR(j,0,51) at[i][j][0]=at[i][j][1]=0;
		l[i]=0;
	}
}
inline int chid(char c){return c>='a'?c-'a'+26:c-'A';}
void solve(){
	n=read();
	FOR(i,0,n-1){
		scanf("%s",str[i]+1);
		l[i]=strlen(str[i]+1);
		reverse(str[i]+1,str[i]+l[i]+1);
		FOR(j,1,l[i]){
			int c=chid(str[i][j]);
			if(at[i][c][0]) at[i][c][1]=j,id[i][j]=1;
			else at[i][c][0]=j,id[i][j]=0;
		}
	}
	int x=0,y=0;
	FOR(_,1,l[0]){
		bool flag=true;
		int S=0,c=chid(str[0][_]);
		FOR(i,0,n-1){
			flag&=!!at[i][c][0];
			if(at[i][c][1]) S|=1<<i;
		}
		if(!flag) continue;
//		printf("%d in\n",c);
		for(int T=S;;T=(T-1)&S){
			if((T&1)==id[0][_]){
				wtf ans=(wtf){1,-1,0};
				FOR(i,0,51){
					int s=0;flag=true;
					FOR(j,0,n-1){
						int p=at[j][c][(T>>j)&1];
						flag&=at[j][i][0] && at[j][i][0]<p;
						if(at[j][i][1] && at[j][i][1]<p) s|=1<<j;
					}
					if(!flag) continue;
					wtf tmp=(wtf){pr[i][s].first+1,i,pr[i][s].second};
					ans=max(ans,tmp);
				}
				f[c][T]=max(f[c][T],ans);
//				printf("f[%d][%d]=%d\n",c,T,f[c][T].l);
				if(f[c][T].l>f[x][y].l) x=c,y=T;
				pr[c][T]=max(pr[c][T],MP(f[c][T].l,T));
			}
			if(!T) break;
		}
		for(int i=1;i<(1<<n);i<<=1)
			for(int j=0;j<n;j+=i<<1)
				FOR(k,0,i-1) pr[c][i+j+k]=max(pr[c][i+j+k],pr[c][j+k]);
	}
	printf("%d\n",f[x][y].l);
	while(f[x][y].l){
		putchar(x<26?x+'A':x-26+'a');
		int xx=x,yy=y;
		x=f[xx][yy].c;
		y=f[xx][yy].s;
	}
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
/*
2
2
abcabc
bcabca
2
ABABCC
BCAABC
*/