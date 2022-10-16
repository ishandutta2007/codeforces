#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,m,l,r;
char s[maxn],t[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	l=1;r=n;
	while(r-l+1>=4){
		if(s[l]==s[r] || s[l]==s[r-1]) t[++m]=s[l];
		else t[++m]=s[l+1];
		l+=2;r-=2;
	}
	FOR(i,1,m) putchar(t[i]);
	if(l<=r) t[++m]=s[l];
	ROF(i,m,1) putchar(t[i]);
}
// PB AK IOI