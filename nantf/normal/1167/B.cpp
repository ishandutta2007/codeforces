#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353,b[6]={4,8,15,16,23,42};
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define fl fflush(stdout)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int a[6];
bool ap(int x){
	FOR(i,0,5) if(x==b[i]) return true;
	return false;
}
int main(){
	puts("? 1 2");
	fl;
	int x=read();
	FOR(i,0,5) FOR(j,0,5) if(b[i]*b[j]==x && i!=j){a[0]=b[i];a[1]=b[j];break;}
	puts("? 1 6");
	fl;
	int y=read();
	if(y%a[0]!=0) swap(a[0],a[1]);
	a[5]=y/a[0];
	puts("? 1 3");
	fl;
	int z=read();
	a[2]=z/a[0];
	puts("? 1 4");
	fl;
	int w=read();
	a[3]=w/a[0];
	if(ap(a[5]) && ap(a[2]) && ap(a[3]));
	else{
		a[5]=y/a[1];
		a[2]=z/a[1];
		a[3]=w/a[1];
		swap(a[0],a[1]);
	}
	a[4]=b[0]+b[1]+b[2]+b[3]+b[4]+b[5]-a[0]-a[1]-a[2]-a[3]-a[5];
	printf("! %d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
	fl;
}