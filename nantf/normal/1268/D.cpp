#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=998244353;
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
int n,deg[maxn],tmp[maxn];
char e[maxn][maxn];
bool check(){
	FOR(i,1,n) tmp[i]=deg[i];
	sort(tmp+1,tmp+n+1);
	int sum=0;
	FOR(i,1,n-1){
		sum+=tmp[i];
		if(sum==i*(i-1)/2) return false;
	}
	return true;
}
void work(int i){
	FOR(j,1,n){
		if(e[i][j]=='1') deg[i]--,deg[j]++;
		else deg[j]--,deg[i]++;
		e[i][j]^=1;e[j][i]^=1;
	}
}
int main(){
	n=read();
	FOR(i,1,n){
		scanf("%s",e[i]+1);
		FOR(j,1,n) if(e[i][j]=='1') deg[i]++;
	}
	if(check()) return puts("0 1"),0;
	if(n>6){
		int ans=0;
		FOR(i,1,n){
			work(i);
			if(check()) ans++;
			work(i);
		}
		printf("1 %d\n",ans);
		return 0;
	}
	int ans1=1e9,ans2=0;
	FOR(i,0,(1<<n)-1){
		int cnt=0;
		FOR(j,1,n) if((i>>(j-1))&1) cnt++,work(j);
		if(check()){
			if(cnt<ans1) ans1=cnt,ans2=0;
			if(cnt==ans1) ans2++;
		}
		ROF(j,n,1) if((i>>(j-1))&1) work(j);
	}
	if(ans1==1e9) puts("-1");
	else{
		FOR(i,1,ans1) ans2*=i;
		printf("%d %d\n",ans1,ans2);
	}
}