#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int t,n,m,a[22][22],b[22][2222],mx[2222],p[2222],sum[22][4444],f[22][4444];
bool cmp(int x,int y){return mx[x]>mx[y];}
int main(){
	t=read();
	while(t--){
		n=read();m=read();
		FOR(i,0,n-1) FOR(j,0,m-1) b[i][j]=read();
		FOR(i,0,m-1){
			mx[i]=0;
			FOR(j,0,n-1) mx[i]=max(mx[i],b[j][i]);
		}
		FOR(i,0,m-1) p[i]=i;
		sort(p,p+m,cmp);
		FOR(i,0,min(n,m)-1) FOR(j,0,n-1) a[j][i]=b[j][p[i]];
		FOR(i,0,min(n,m)-1) FOR(S,0,(1<<n)-1){
			sum[i][S]=0;
			FOR(j,0,n-1){
				int s=0;
				FOR(k,0,n-1) if((S>>k)&1) s+=a[(j+k)%n][i];
				sum[i][S]=max(sum[i][S],s);
			}
		}
		FOR(S,0,(1<<n)-1) f[0][S]=sum[0][S];
		FOR(i,1,min(n,m)-1) FOR(S,0,(1<<n)-1){
			f[i][S]=f[i-1][S];
			for(int S0=S;S0;S0=(S0-1)&S) f[i][S]=max(f[i][S],f[i-1][S^S0]+sum[i][S0]);
		}
		printf("%d\n",f[min(n,m)-1][(1<<n)-1]);
	}
}