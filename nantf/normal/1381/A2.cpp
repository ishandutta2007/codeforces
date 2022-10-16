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
int T,n,ans[maxn*2],al;
char a[maxn],b[maxn];
void solve(){
	n=read();
	scanf("%s%s",a+1,b+1);
	al=0;
	int nn=n;
	for(;n;n--){
		if(a[1]==b[n]){
			ans[++al]=1;
			a[1]^=1;
		}
		ans[++al]=n;
		a[1]=a[n%2==nn%2?nn-(nn-n)/2:(nn-n)/2+2]^(n%2==nn%2?1:0);
	}
	printf("%d ",al);
	FOR(i,1,al) printf("%d ",ans[i]);
	puts("");
}
int main(){
	T=read();
	while(T--) solve();
}
// 123456
// 654321
// 234561
// 543261
// 345261
// 435261
/*
5
2
01
10
3 1 2 1

5
11100
11100
8 1 5 1 4 1 3 2 1

2
01
01
3 2 1 1

10
0110011011
1000110100
19 1 10 1 9 1 8 1 7 1 6 1 5 1 4 1 3 1 2 1

1
0
1
1 1
*/