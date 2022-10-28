#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}
const int maxn=100005;
int p[maxn],d[maxn];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=2;i<=n;++i)d[i]=(p[i-1]<p[i]);
	int MX=0,CNT=0;
	for(int l=2,r=2;l<=n;l=r=r+1){
		int o=d[l];
		while(r+1<=n&&o==d[r+1])++r;
		int len=r-l+2;
		if(len>MX)MX=len,CNT=1;
		else if(len==MX)++CNT;
	}
	if(CNT!=2||(MX&1)==0)return puts("0"),0;
	int ok=false;
	for(int i=3;i<=n&&!ok;++i){
		if(d[i-1]&&!d[i]){
			int l=i-1,r=i;
			while(l>2&&d[l-1])--l;
			while(r<n&&!d[r+1])++r;
			if((i-1)-(l-1)+1==MX&&r-(i-1)+1==MX)
				ok=true;
		}
	}
	write(ok),pc('\n');
	return 0;
}