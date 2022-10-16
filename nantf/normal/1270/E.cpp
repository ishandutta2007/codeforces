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
int n,x[maxn],y[maxn];
int main(){
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read();
	while(true){
		int ecnt=0,ocnt=0;
		FOR(i,1,n){
			if((x[i]+y[i])%2==0) ecnt++;
			else ocnt++;
		}
		if(ecnt && ocnt){
			printf("%d\n",ecnt);
			FOR(i,1,n) if((x[i]+y[i])%2==0) printf("%d ",i);
			return 0; 
		} 
		if(ecnt){
			FOR(i,1,n){
				int xx=(x[i]+y[i])/2,yy=(y[i]-x[i])/2;
				x[i]=xx;y[i]=yy;
			} 
		}
		else{
			FOR(i,1,n){
				int xx=(x[i]+y[i]-1)/2,yy=(y[i]-x[i]-1)/2;
				x[i]=xx;y[i]=yy;
			}
		}
	}
}