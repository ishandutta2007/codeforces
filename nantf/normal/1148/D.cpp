#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222222;
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
	int a,b,id;
	bool operator<(const item &i)const{return b<i.b;}
}t1[maxn],t2[maxn]; 
int n,m1,m2,a[maxn],b[maxn],al1,ans1[maxn],al2,ans2[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),b[i]=read();
	FOR(i,1,n) if(a[i]>b[i]) t1[++m1]=(item){a[i],b[i],i};
	sort(t1+1,t1+m1+1);
	FOR(i,1,m1) if(t1[i].a>t1[ans1[al1]].b) ans1[++al1]=i;
	FOR(i,1,n) if(a[i]<b[i]) t2[++m2]=(item){a[i],b[i],i};
	sort(t2+1,t2+m2+1);
	t2[0].b=1e9;
	ROF(i,m2,1) if(t2[i].a<t2[ans2[al2]].b) ans2[++al2]=i;
	if(al1>al2){
		printf("%d\n",al1);
		FOR(i,1,al1) printf("%d ",t1[ans1[i]].id);
	}
	else{
		printf("%d\n",al2);
		FOR(i,1,al2) printf("%d ",t2[ans2[i]].id);
	}
}