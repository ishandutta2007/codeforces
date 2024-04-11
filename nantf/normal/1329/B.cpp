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
int t,d,mod,ans,f[31];
int main(){
	t=read();
	while(t--){
		d=read();mod=read();
		if(mod==1){puts("0");continue;}
		int lim=1,l=0;
		while(lim<=d) lim<<=1,l++;
		lim>>=1,l--;
		ans=0;
		f[0]=0;
		FOR(i,1,l) f[i]=(f[i-1]+1ll*(1+f[i-1])*(1<<(i-1)))%mod;
		ans=(f[l]+1ll*(1+f[l])*(d-lim+1))%mod;
		printf("%d\n",ans);
	}
}