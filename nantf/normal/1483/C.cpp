#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
int n,h[maxn],b[maxn],stk[maxn],tp;
ll f[maxn],mx[maxn];
multiset<ll,greater<ll> > s;
int main(){
	n=read();
	FOR(i,1,n) h[i]=read();
	FOR(i,1,n) b[i]=read();
	f[1]=b[1];
	stk[tp=1]=1;
	mx[1]=0;
	s.insert(b[1]);
	FOR(i,2,n){
		f[i]=-1e18;
		ll tmp=-1e18;
		while(tp && h[i]<h[stk[tp]]){
			auto it=s.find(mx[tp]+b[stk[tp]]);
			s.erase(it);
//			printf("erase %lld\n",mx[tp]+b[stk[tp]]);
			tmp=max(tmp,mx[tp]);
			tp--;
		}
//		printf("tmp=%lld\n",tmp);
		f[i]=max(f[i],f[i-1]+b[i]);
		if(!s.empty()) f[i]=max(f[i],*s.begin());
		f[i]=max(f[i],tmp+b[i]);
		stk[++tp]=i;
		mx[tp]=max(tmp,f[i-1]);
		s.insert(mx[tp]+b[stk[tp]]);
//		printf("insert %lld\n",mx[tp]+b[stk[tp]]);
//		printf("f[%d]=%lld\n",i,f[i]);
	}
	printf("%lld\n",f[n]);
}
/*
2
1 2
3 -4
*/