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
int t,n;
char s[maxn];
bool ans[26];
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		MEM(ans,0);
		FOR(i,1,n){
			int j=i;
			while(j<=n && s[j]==s[i]) j++;
			j--;
			if((j-i+1)%2==1) ans[s[i]-'a']=true;
			i=j;
		}
		FOR(i,0,25) if(ans[i]) putchar(i+'a');
		puts("");
	}
}