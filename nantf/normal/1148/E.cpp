#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1500150;
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
struct item{
	int s,id;
	bool operator<(const item &i)const{return s<i.s;}
}it[maxn];
int n,s[maxn],t[maxn],d[maxn],cur=1,m,a[maxn],b[maxn],c[maxn];
ll sum;
int main(){
	n=read();
	FOR(i,1,n) s[i]=read(),it[i]=(item){s[i],i};
	FOR(i,1,n) t[i]=read();
	sort(it+1,it+n+1);sort(t+1,t+n+1);
	FOR(i,1,n) d[i]=t[i]-it[i].s,sum+=d[i];
	if(sum) return puts("NO"),0;
	FOR(i,1,n){
		if(d[i]<0) return puts("NO"),0;
		while(d[i]){
			while(cur<=n && d[cur]>=0) cur++;
			int x=min(d[i],-d[cur]);
			d[i]-=x;d[cur]+=x;
			a[++m]=it[i].id;b[m]=it[cur].id;c[m]=x;
		}
	}
	printf("YES\n%d\n",m);
	FOR(i,1,m) printf("%d %d %d\n",a[i],b[i],c[i]);
}
// orz CDW AK