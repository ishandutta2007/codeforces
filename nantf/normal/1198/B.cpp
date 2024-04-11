#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
struct item{
	int a,id;
	bool operator<(const item &i)const{return a<i.a;}
}it[maxn];
int n,q,a[maxn],ans[maxn],op[maxn],x[maxn],y[maxn],seq[maxn],tim[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	q=read();
	FOR(i,1,q){
		op[i]=read();x[i]=read();
		if(op[i]==1) a[x[i]]=read(),tim[x[i]]=i;
		else seq[i]=x[i];
	}
	ROF(i,q,1) seq[i]=max(seq[i],seq[i+1]);
	FOR(i,1,n) a[i]=max(a[i],seq[tim[i]+1]);
	FOR(i,1,n) printf("%d ",a[i]);
}