#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=266666,mod=998244353,INF=1e9;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int d,p,t[22][22],w[22],C[22][22];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%p) if(b&1) ans=1ll*ans*a%p;
	return ans;
}
inline void add(int a,int b,int c){
	printf("+ %d %d %d\n",a,b,c);
}
inline void mul(int a,int b){
	printf("^ %d %d\n",a,b);
}
inline void ans(int a){
	printf("f %d\n",a);
	exit(0);
}
inline void qmul(int a,int b,int x){
	add(4999,a,5000);add(4999,4999,b);
	for(;x;x>>=1,add(5000,5000,5000)) if(x&1) add(b,5000,b);
}
inline void sub(int a,int b,int c){
	qmul(b,4000,p-1);
	add(a,4000,c);
}
inline void sq(int a,int b){
	add(4999,a,3000);mul(4999,b);
	FOR(i,1,d) add(3000+i-1,2999,3000+i);
	FOR(i,0,d) mul(3000+i,3000+i),qmul(3000+i,3000+i,w[i]),add(3000+i,b,b);
}
void init(){
	int pp=p-1;
	for(;pp;pp>>=1,add(5000,5000,5000)) if(pp&1) add(4999,5000,4999);
	FOR(i,0,d) C[i][0]=C[i][i]=1;
	FOR(i,1,d) FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	FOR(i,0,d){
		FOR(j,0,d) t[i][j]=1ll*C[d][i]*qpow(j,d-i)%p;
		t[i][d+1]=i==2;
	}
	FOR(i,0,d){
		FOR(j,i,d) if(t[j][i]){swap(t[i],t[j]);break;}
		int inv=qpow(t[i][i],p-2);
		FOR(j,0,d+1) t[i][j]=1ll*t[i][j]*inv%p;
		FOR(j,0,d) if(j!=i){
			int x=t[j][i];
			FOR(k,0,d+1) t[j][k]=(t[j][k]-1ll*x*t[i][k]%p+p)%p;
		}
	}
	FOR(i,0,d) w[i]=t[i][d+1];
}
int main(){
	d=read();p=read();
	init();
	add(1,2,3);
	sq(1,4);sq(2,5);sq(3,6);
	sub(6,5,7);sub(7,4,8);
	qmul(8,9,(p+1)/2);ans(9);
}