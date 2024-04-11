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
int t,n,cnt[26],al,bl,aa[maxn],bb[maxn];
char s[maxn];
int main(){
	t=read();
	while(t--){
		MEM(cnt,0);MEM(aa,0);MEM(bb,0);MEM(s,0);al=bl=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		FOR(i,1,n) cnt[s[i]-'a']++;
		for(int i=0;i<=25;i+=2) if(cnt[i]) aa[++al]=i;
		int u=666,v=233;
		for(int i=1;i<=25;i+=2) if(cnt[i]){
			bool flag=false;
			if(u==666){
				FOR(j,1,al) if(abs(i-aa[j])!=1){u=aa[j];v=i;flag=true;break;}
			}
			if(!flag) bb[++bl]=i;
		}
		if(u!=666 || !al || !bl){
			FOR(i,1,al) if(aa[i]!=u) FOR(j,1,cnt[aa[i]]) putchar(aa[i]+'a');
			if(u!=666) FOR(i,1,cnt[u]) putchar(u+'a');
			if(v!=233) FOR(i,1,cnt[v]) putchar(v+'a');
			FOR(i,1,bl) FOR(j,1,cnt[bb[i]]) putchar(bb[i]+'a');
			putchar('\n');
		}
		else puts("No answer");
	}
}