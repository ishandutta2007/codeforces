#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=222222;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct segment{
	int l,r;
	bool operator<(const segment &s)const{
		if(r!=s.r) return r<s.r;
		return l<s.l;
	}
}seg[maxn];
int n,cnt;
int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),w=read();
		seg[i]=(segment){x-w,x+w};
	}
	sort(seg+1,seg+n+1);
	FOR(i,1,n){
		cnt++;
		int j=i+1;
		while(j<=n && seg[j].l<seg[i].r) j++;
		i=j-1;
	}
	printf("%d\n",cnt);
}