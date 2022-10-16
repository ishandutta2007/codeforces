#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,w[maxn],nxt[maxn],fa[maxn],stk[maxn],tp;
ll sum;
__int128 ans;
map<int,int> mp;
char c[10],s[maxn];
inline void write(__int128 x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
	n=read();
	FOR(i,1,n){
		scanf("%s",c+1);
		s[i]=(c[1]-'a'+ans)%26+'a';
		w[i]=read()^(ans&((1<<30)-1));
		while(tp && w[i]<=w[stk[tp]]) tp--;
		stk[++tp]=i;
		if(i!=1){
			int j=nxt[i-1];
			while(j && s[i]!=s[j+1]) j=nxt[j];
			if(s[i]==s[j+1]) j++;
			nxt[i]=j;
			if(s[i]==s[nxt[i-1]+1]) fa[i-1]=fa[nxt[i-1]];
			else fa[i-1]=nxt[i-1];
			while(!mp.empty() && mp.rbegin()->first>w[i]){
				map<int,int>::iterator it=--mp.end();
				sum+=1ll*(w[i]-it->first)*it->second;
				mp[w[i]]+=it->second;
				mp.erase(it);
			}
			int now=nxt[i-1];
			while(now){
				if(s[now+1]==s[i]){
					now=fa[now];
				}
				else{
					int tmp=w[*lower_bound(stk+1,stk+tp+1,i-now)];
					sum-=tmp;
					if(!--mp[tmp]) mp.erase(tmp);
					now=nxt[now];
				}
			}
			if(s[1]==s[i]){
				mp[w[i]]++;
				sum+=w[i];
			}
		}
		ans+=w[stk[1]];
		ans+=sum;
		write(ans);puts("");
	}
}