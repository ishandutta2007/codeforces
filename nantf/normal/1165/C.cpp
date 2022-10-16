#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m;
char s[maxn];
bool use[maxn];
int main(){
	n=read();
	scanf("%s",s+1);
	int cnt=0;
	FOR(i,1,n){
		if(s[i]==s[i-1]) cnt++;
		else cnt=1;
		if(cnt<=2) use[i]=true;
	}
	int pos=1,pre=0;
	FOR(i,1,n) if(use[i]){
		if(pos%2==0){
			if(s[i]==s[pre]) use[i]=false;
			else pos++,pre=i;
		}
		else pos++,pre=i;
	}
	pos--;
	if(pos&1) pos--;
	printf("%d\n",n-pos);
	FOR(i,1,n) if(use[i] && pos) putchar(s[i]),pos--;
	putchar('\n');
}