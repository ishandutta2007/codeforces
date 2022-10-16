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
int q,n,m,k,cnt[26],cnt2[26];
char s[maxn],t[maxn],p[maxn];
int main(){
	q=read();
	while(q--){
		scanf("%s%s%s",s+1,t+1,p+1);
		n=strlen(s+1);
		m=strlen(t+1);
		k=strlen(p+1);
		FOR(i,1,k) cnt[p[i]-'a']++;
		int cur=1;
		FOR(i,1,m){
			if(cur<=n && s[cur]==t[i]) cur++;
			else cnt2[t[i]-'a']++;
		}
		if(cur!=n+1) puts("NO");
		else{
			bool flag=true;
			FOR(i,0,25) if(cnt[i]<cnt2[i]){puts("NO");flag=false;break;}
			if(flag) puts("YES");
		}
		FOR(i,0,25) cnt[i]=cnt2[i]=0;
	}
}