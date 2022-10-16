#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,cnt[maxn],ans,dp[maxn][5][5];
int main(){
	n=read();m=read();
	FOR(i,1,n) cnt[read()]++;
	MEM(dp,~0x3f);
	FOR(i,0,min(4,cnt[1])) dp[1][i][0]=(cnt[1]-i)/3;
	FOR(i,2,m) FOR(j,0,4){
		if(j>cnt[i]) break;
		FOR(k,0,4){
			if(k>cnt[i-1]) break;
			FOR(l,0,2){
				if(j+l>cnt[i] || k+l>4 || k+l>cnt[i-1] || l>cnt[i-2]) break;
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][k+l][l]+l+(cnt[i]-l-j)/3);
			}
		}
	}
	printf("%d\n",dp[m][0][0]);
}