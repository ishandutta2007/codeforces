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
int n,ch[maxn*2],len;
struct hhh{
	int d,id;
	bool operator<(const hhh &h)const{return d>h.d;}
}h[maxn];
int main(){
	n=read();
	FOR(i,1,n) h[i]=(hhh){read(),i};
	sort(h+1,h+n+1);
	FOR(i,1,n) ch[i]=2*h[i].id;
	FOR(i,1,n-1) printf("%d %d\n",ch[i],ch[i+1]);
	len=n;
	FOR(i,1,n){
		int id=2*h[i].id-1;
		printf("%d %d\n",ch[i+h[i].d-1],id);
		if(i+h[i].d-1==len) ch[++len]=id;
	}
}