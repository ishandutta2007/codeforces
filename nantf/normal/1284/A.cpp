#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=22;
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
int n,m,q;
char s[maxn][maxn],t[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,0,n-1) scanf("%s",s[i]+1);
	FOR(i,0,m-1) scanf("%s",t[i]+1);
	q=read();
	while(q--){
		int y=read()-1;
		printf("%s%s\n",s[y%n]+1,t[y%m]+1);
	}
}