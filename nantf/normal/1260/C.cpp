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
int t,a,b,k;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		a=read();b=read();k=read();
		if(k==1) puts("REBEL");
		else if(a==b) puts("OBEY");
		else{
			if(a<b) swap(a,b);
			int g=gcd(a,b);
			a/=g;b/=g;
			if(a-1<=1ll*(k-1)*b) puts("OBEY");
			else puts("REBEL");
		}
	}
}