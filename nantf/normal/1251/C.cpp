#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
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
int t,n,ol,el,od[maxn],ev[maxn];
char s[maxn];
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ol=el=0;
		FOR(i,1,n) if((s[i]-'0')%2) od[++ol]=s[i]-'0';
		else ev[++el]=s[i]-'0';
		int i=1,j=1;
		while(i<=ol && j<=el){
			if(od[i]<ev[j]) printf("%d",od[i++]);
			else printf("%d",ev[j++]);
		}
		while(i<=ol) printf("%d",od[i++]);
		while(j<=el) printf("%d",ev[j++]);
		puts("");
	}
}