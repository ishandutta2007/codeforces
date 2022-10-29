#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=1005;
const int mo=1e9+7;

void add(int &a,int b){(a+=b)%=mo;}

char str[N];
int a[N],n,k;
int dp[N][N];

int dfs(int p,int num,int limit) {
	if (num<0) return 0;
	if (!limit&&~dp[p][num]) return dp[p][num];
	if (num>p) return 0;
	if (!p) return num==0;
	int up=limit?a[p]:1,res=0;
	rep(i,0,up+1) {
		add(res,dfs(p-1,num-(i==1),limit&&i==up));
	}
	if (!limit) dp[p][num]=res;
	return res;
}

int cnt[1005],g[1005];
int lowbit(int x){return x&-x;}

int main() {
	rep(i,1,1001) cnt[i]=cnt[i-lowbit(i)]+1;
	rep(i,2,1001) g[i]=g[cnt[i]]+1;
	memset(dp,-1,sizeof(dp));
	
	scanf("%s%d",str,&k);
	n=strlen(str);
	if (!k) return puts("1"),0;
	if (k==1) {printf("%d\n",n-1); return 0;}
	
	reverse(str,str+n);
	rep(i,1,n+1) a[i]=str[i-1]-'0';
	
	int ans=0;
	rep(i,1,1001) if (g[i]==k-1) {
		int tmp=dfs(n,i,1);
		add(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;	
}