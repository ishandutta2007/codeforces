#include<bits/stdc++.h>
using namespace std;
const int maxn=111111;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct node{
	int id,val;
	bool operator<(const node &nd)const{return val>nd.val;}
};
int n,k,q,a[13][maxn],cnt;
node b[maxn][13];
bitset<4096> bs[maxn];
int main(){
	n=read();k=cnt=read();q=read();
	FOR(i,1,k){
		FOR(j,1,n){
			a[i][j]=read();
			b[j][i]=(node){i,a[i][j]};
		}
		FOR(s,0,(1<<k)-1) if(s&(1<<(i-1))) bs[i].set(s);
	}
	FOR(i,1,n) sort(b[i]+1,b[i]+k+1);
	while(q--){
		int op=read(),x=read(),y=read();
		if(op==1) bs[++cnt]=bs[x]|bs[y];
		if(op==2) bs[++cnt]=bs[x]&bs[y];
		if(op==3){
			int s=0;
			FOR(i,1,k){
				s|=1<<(b[y][i].id-1);
				if(bs[x][s]==1){
					printf("%d\n",b[y][i].val);break;
				}
			}
		}
	}
}