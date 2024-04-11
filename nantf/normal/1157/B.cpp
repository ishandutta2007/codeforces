#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,a[maxn];
char s[maxn];
int f[10];
int main(){
	n=read();
	scanf("%s",s+1);
	FOR(i,1,n) a[i]=s[i]-'0';
	FOR(i,1,9) f[i]=read();
	bool start=false;
	FOR(i,1,n){
		if(f[a[i]]>a[i]) start=true;
		if(f[a[i]]<a[i] && start) break;
		if(start) a[i]=f[a[i]];
	}
	FOR(i,1,n) printf("%d",a[i]);
}