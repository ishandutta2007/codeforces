#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=88;
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
int n,k,w[maxn][maxn],ans=1e9,seq[maxn],cnt[maxn];
PII www[maxn][maxn][4];
int calc(){
	int s=0;
	FOR(i,1,k/2) FOR(j,0,3){
		if(!www[seq[i]][seq[i-1]][j].second) return 1e9;
		if(!cnt[www[seq[i]][seq[i-1]][j].second]){s+=www[seq[i]][seq[i-1]][j].first;break;}
	}
	return s;
}
void dfs(int dep){
	if(dep>=k/2) return void(ans=min(ans,calc()));
	FOR(i,1,n){
		cnt[i]++;
		seq[dep]=i;
		dfs(dep+1);
		cnt[i]--;
	}
}
int main(){
	n=read();k=read();
	FOR(i,1,n) FOR(j,1,n) w[i][j]=read();
	FOR(i,1,n) w[i][i]=1e9;
	FOR(i,1,n) FOR(j,1,n){
		FOR(k,0,3) www[i][j][k]=MP(1e9,0);
		FOR(k,1,n){
			FOR(x,0,3) if(w[i][k]+w[k][j]<www[i][j][x].first){
				ROF(y,3,x+1) www[i][j][y]=www[i][j][y-1];
				www[i][j][x]=MP(w[i][k]+w[k][j],k);
				break;
			}
		}
	}
	seq[0]=seq[k/2]=1;
	cnt[1]=1;
	dfs(1);
	printf("%d\n",ans);
}
// stupid me