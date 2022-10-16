#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,a[maxn],b[maxn],tmp[maxn][2],tl,al;
vector<int> ans[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),b[i]=1;
	while(true){
		int x=0,y=0;
		FOR(i,1,n) FOR(j,i+1,n) if(a[i]==a[j]+1) x=i,y=j;
		if(!x) break;
		al++;
		int sum=0;
		FOR(i,1,x-1) sum+=b[i];
		if(sum) ans[al].PB(sum),sum=0;
		FOR(i,x,y-1) sum+=b[i];
		if(sum) ans[al].PB(sum),sum=0;
		ans[al].PB(b[y]);
		FOR(i,y+1,n) sum+=b[i];
		if(sum) ans[al].PB(sum);
		tl=0;
		FOR(i,y+1,n) tmp[++tl][0]=a[i],tmp[tl][1]=b[i];
		int tttttt=tl;
		FOR(i,x,y-1) tmp[++tl][0]=a[i],tmp[tl][1]=b[i];
		tmp[tttttt+1][1]+=b[y];
		FOR(i,1,x-1) tmp[++tl][0]=a[i],tmp[tl][1]=b[i];
		n--; 
		FOR(i,1,n) a[i]=tmp[i][0],b[i]=tmp[i][1];
		FOR(i,1,n){
			tmp[i][0]=0;
			FOR(j,1,n) if(a[j]<=a[i]) tmp[i][0]++;
		}
		FOR(i,1,n) a[i]=tmp[i][0];
	}
	printf("%d\n",al);
	FOR(i,1,al){
		printf("%d ",(int)ans[i].size());
		FOR(j,0,(int)ans[i].size()-1) printf("%d ",ans[i][j]);
		puts("");
	}
}