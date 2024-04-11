#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
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
int n,p[maxn],id[maxn],m,a[maxn*5],b[maxn*5];
int tp(int x){return x<=n/2?0:1;}
int main(){
	n=read();
	FOR(i,1,n) id[p[i]=read()]=i;
	FOR(i,1,n){
		if(p[i]==i) continue;
		int x=i,y=id[i],t1=tp(x),t2=tp(y);
		if(abs(x-y)*2>=n){
			m++;
			a[m]=x;b[m]=y;
		}
		else if(t1==t2){
			int ot=t1?1:n;
			m++;
			a[m]=x;b[m]=ot;
			m++;
			a[m]=y;b[m]=ot;
			m++;
			a[m]=x;b[m]=ot;
		}
		else{
			if(t1>t2) swap(x,y),swap(t1,t2);
			m++;
			a[m]=x;b[m]=n;
			m++;
			a[m]=1;b[m]=y;
			m++;
			a[m]=1;b[m]=n;
			m++;
			a[m]=1;b[m]=y;
			m++;
			a[m]=x;b[m]=n;
		}
		swap(p[x],p[y]);
		id[p[x]]=x;
		id[p[y]]=y;
//		FOR(j,1,n) printf("%d ",p[j]);
//		puts("");
	}
	printf("%d\n",m);
	FOR(i,1,m) printf("%d %d\n",a[i],b[i]);
}