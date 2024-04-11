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
int m,n,s[55];
bool ss[55][10010];
int main(){
	m=read();n=read();
	FOR(i,1,m){
		s[i]=read();
		FOR(j,1,s[i]) ss[i][read()]=true;
		FOR(j,1,i-1){
			int cnt=0;
			FOR(k,1,n) if(ss[i][k] && ss[j][k]) cnt++;
			if(!cnt) return puts("impossible"),0;
		}
	}
	puts("possible");
}
// orz ZZ solved it