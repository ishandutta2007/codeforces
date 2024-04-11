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
int n,q,pre[maxn][26];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n){
		FOR(j,0,25) pre[i][j]=pre[i-1][j];
		pre[i][s[i]-'a']++;
	}
	q=read();
	while(q--){
		int l=read(),r=read();
		if(l==r) puts("Yes");
		else{
			int cnt=0;
			FOR(i,0,25) if(pre[r][i]-pre[l-1][i]) cnt++;
			puts(cnt>=3 || l==r || s[l]!=s[r] ? "Yes" : "No"); 
		}
	}
}
// shit constructive problem