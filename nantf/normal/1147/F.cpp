#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
int n,w[maxn][maxn],to[maxn],at[maxn],l[maxn][maxn],q[2][maxn],ql[2];
bool vis[maxn][maxn];
char tmp[maxn];
void clear(){
	FOR(i,0,2*n) FOR(j,0,2*n) w[i][j]=l[i][j]=vis[i][j]=0;
	FOR(i,0,2*n) to[i]=at[i]=0;
}
int aaa,ttt;
inline bool cmp(int x,int y){
	if(ttt) return w[x][aaa]>w[y][aaa];
	else return w[aaa][x]>w[aaa][y];
}
void work(int tp){
	int cur=0;
	ql[0]=0;
	FOR(i,tp*n+1,tp*n+n){
		FOR(j,1,n) l[i][j]=(tp^1)*n+j;
		at[i]=1;
		aaa=i;ttt=tp;
		sort(l[i]+1,l[i]+n+1,cmp);
		q[0][++ql[0]]=i;
	}
	while(ql[cur]){
		ql[cur^1]=0;
		FOR(ii,1,ql[cur]){
			int i=q[cur][ii];
			while(at[i]<=n && vis[i][l[i][at[i]]]) at[i]++;
//			assert(at[i]<=n);
			int j=l[i][at[i]];
			if(!to[j] || (tp?w[j][i]<w[j][to[j]]:w[i][j]<w[to[j]][j])){
				if(to[j]){
					vis[to[j]][j]=true;
					q[cur^1][++ql[cur^1]]=to[j];
					to[to[j]]=0;
				}
				to[i]=j;to[j]=i;
			}
			else{
				vis[i][j]=true;
				q[cur^1][++ql[cur^1]]=i;
			}
		}
		cur^=1;
	}
}
void solve(){
	n=read();
	FOR(i,1,n) FOR(j,n+1,2*n) w[i][j]=read();
	puts("B");
	fflush(stdout);
	scanf("%s",tmp);
	if(tmp[0]=='I') FOR(i,1,n) FOR(j,n+1,2*n) w[i][j]=-w[i][j];
	int x=read();
	work(x>n);
	while(true){
		printf("%d\n",to[x]);
		fflush(stdout);
		x=read();
		if(x==-1) break;
		if(x==-2) exit(0);
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}