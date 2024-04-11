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
struct hhh{
	int x,id;
	bool operator<(const hhh &h)const{return x<h.x;}
}h[maxn];
int n,cnt;
int main(){
	n=read();
	FOR(i,1,n) h[i].x=read(),h[i].id=i;
	sort(h+1,h+n+1);
	FOR(i,1,n){
		int pos=0;
		FOR(j,1,i-1) if(h[i].x%h[j].x==0) pos=j;
		if(!pos) cnt++;
	}
	printf("%d\n",cnt);
}