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
int n,tot,last,ans,mn;
char s[maxn];
int main(){
	n=read();
	scanf("%s",s+1); 
	mn=1e9;
	FOR(i,1,n){
		if(s[i]=='(') tot++;
		if(s[i]==')') tot--;
		mn=min(mn,tot);
		if(!tot){
			if(mn<0) ans+=i-last;
			mn=1e9;
			last=i;
		}
	}
	if(tot) puts("-1");
	else printf("%d\n",ans);
}