#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int n,a[maxn],ans[maxn],al,cnt[maxn];
inline int mex(){
	FOR(i,0,n) cnt[i]=0;
	FOR(i,1,n) cnt[a[i]]++;
	FOR(i,0,n) if(!cnt[i]) return i;
}
inline void work(int i){
//	printf("work %d\n",i);
	a[ans[++al]=i]=mex();
//	printf("become %d\n",a[i]);
}
void solve(){
	al=0;
	n=read();
	FOR(i,1,n) a[i]=read();
/*	FOR(i,1,n){
		if(a[i]==i-1) continue;
		bool flag=false;
		ROF(j,n,i+1) if(a[j]==i-1){
			if(flag) a[ans[++al]=j]=mex();
			flag=true;
		}
		a[ans[++al]=i]=mex();
	}
	FOR(i,0,n){
		bool flag=false;
		FOR(j,1,n) if(a[j]==i){
			if(flag || i==n) a[ans[++al]=j]=mex();
			flag=true;
		}
	}
	FOR(i,1,n) printf("%d ",a[i]);
	puts("");*/
	FOR(i,1,n){
		int x=mex();
		if(x==n){
			bool flag=false;
			FOR(j,1,n) if(a[j]!=j-1){
				flag=true;work(j);break;
			}
			if(!flag) break;
		}
		x=mex();
		assert(x!=n);
		if(a[x+1]!=x) work(x+1);
	}
	printf("%d\n",al);
	FOR(i,1,al) printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--) solve();
}