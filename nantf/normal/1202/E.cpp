#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
struct ACAM{
	int cnt,ch[maxn][26],fail[maxn],q[maxn],sum[maxn],h,r,val[maxn];
	void insert(char *s,int l){
		int now=0;
		FOR(i,1,l){
			int p=s[i]-'a';
			if(!ch[now][p]) ch[now][p]=++cnt;
			now=ch[now][p];
		}
		sum[now]++;
	}
	void build(){
		h=1;r=0;
		FOR(i,0,25) if(ch[0][i]) q[++r]=ch[0][i];
		while(h<=r){
			int u=q[h++];
			FOR(i,0,25) if(ch[u][i]){
				fail[ch[u][i]]=ch[fail[u]][i];
				sum[ch[u][i]]+=sum[fail[ch[u][i]]];
				q[++r]=ch[u][i];
			}
			else ch[u][i]=ch[fail[u]][i];
		}
	}
	void run(char *s,int l){
		int now=0;
		FOR(i,1,l){
			int p=s[i]-'a';
			now=ch[now][p];
			val[i]=sum[now];
		}
	}
}AC[2];
int n,l;
ll ans;
char t[maxn],s[maxn];
int main(){
	scanf("%s",t+1);l=strlen(t+1);
	n=read();
	FOR(i,1,n){
		scanf("%s",s+1);
		int len=strlen(s+1);
		AC[0].insert(s,len);
		for(int j=1,k=len;j<k;j++,k--) swap(s[j],s[k]);
		AC[1].insert(s,len);
	}
	AC[0].build();AC[1].build();
	AC[0].run(t,l);
	for(int i=1,j=l;i<j;i++,j--) swap(t[i],t[j]);
	AC[1].run(t,l);
	FOR(i,1,l) ans+=1ll*AC[0].val[i]*AC[1].val[l-i];
	cout<<ans<<endl;
}