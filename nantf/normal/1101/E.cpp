#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,maxx,maxy;
int main(){
	n=read();
	FOR(i,1,n){
		char str[5];
		scanf("%s",str);
		int x=read(),y=read();
		if(x>y) swap(x,y);
		if(str[0]=='+') maxx=max(maxx,x),maxy=max(maxy,y);
		else puts(x>=maxx && y>=maxy?"YES":"NO");
	}
}