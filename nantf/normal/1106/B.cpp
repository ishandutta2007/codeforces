#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct dish{
	int rem,cost,id;
	bool operator<(const dish &d)const{
		return cost<d.cost;
	}
}ds[maxn];
int n,m,fst,id[maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) ds[i].rem=read(),ds[i].id=i;
	FOR(i,1,n) ds[i].cost=read();
	sort(ds+1,ds+n+1);
	FOR(i,1,n) id[ds[i].id]=i;
	fst=1;
	while(m--){
		int t,d;ll ans=0;
		t=read();d=read();
		if(fst>n){puts("0");continue;}
		if(d<=ds[id[t]].rem){
			printf("%I64d\n",1ll*ds[id[t]].cost*d);
			ds[id[t]].rem-=d;
			while(fst<=n && !ds[fst].rem) fst++;
			continue;
		}
		ans=1ll*ds[id[t]].cost*ds[id[t]].rem;
		d-=ds[id[t]].rem;
		ds[id[t]].rem=0;
		while(fst<=n && !ds[fst].rem) fst++;
		bool flag=false;
		while(d){
			if(fst>n) break;
			if(d<=ds[fst].rem){
				printf("%I64d\n",1ll*ds[fst].cost*d+ans);
				ds[fst].rem-=d;
				while(fst<=n && !ds[fst].rem) fst++;
				flag=true;
				break;
			}
			ans+=1ll*ds[fst].cost*ds[fst].rem;
			d-=ds[fst].rem;
			ds[fst].rem=0;
			while(fst<=n && !ds[fst].rem) fst++;
		}
		if(!flag) printf("0\n");
	}
}