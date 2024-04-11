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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n;
char s[maxn],t[maxn];
bool check(int x){
	FOR(i,1,n) t[i]=s[(i+x-1)%n+1];
	bool flag=false;
	FOR(i,1,n) if(s[i]!=t[i]){flag=true;break;}
	if(!flag) return false;
	FOR(i,1,n/2) if(t[i]!=t[n-i+1]) return false;
	return true;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n&1){
		int lst=1;
		FOR(i,2,n){
			if(i==n/2+1) continue;
			if(s[i]!=s[lst]) return puts("2"),0;
			lst=i;
		}
		return puts("Impossible"),0;
	}
	bool flag=true;
	FOR(i,1,n-1) if(s[i]!=s[i+1]){flag=false;break;}
	if(flag) return puts("Impossible"),0;
	FOR(i,1,n-1) if(check(i)) return puts("1"),0;
	puts("2");
}