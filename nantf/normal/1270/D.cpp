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
int n,k,a[maxn],mxa,ans;
int main(){
	n=read();k=read();
	FOR(i,1,k+1){
		printf("? ");
		FOR(j,1,k+1) if(i!=j) printf("%d ",j);
		puts("");
		fflush(stdout);
		read();a[i]=read();
		mxa=max(mxa,a[i]);
	}
	FOR(i,1,k+1) if(a[i]==mxa) ans++;
	printf("! %d\n",ans);
	fflush(stdout);
}