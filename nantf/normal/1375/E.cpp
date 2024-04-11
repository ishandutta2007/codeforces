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
int n,a[maxn],cnt;
PII p[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),p[i]=MP(a[i],i);
	sort(p+1,p+n+1);
	FOR(ii,1,n){
		int i=p[ii].second;
		ROF(j,n,i+1) if(a[i]>a[j]) cnt++;
	}
	printf("%d\n",cnt);
	FOR(ii,1,n){
		int i=p[ii].second;
		ROF(j,n,i+1) if(a[i]>a[j]) printf("%d %d\n",i,j);
	}
}