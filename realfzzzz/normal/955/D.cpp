#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5;
int n,m,k;
char s[maxn],t[maxn];
int nxt[maxn],mn[maxn],mx[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	scanf("%s%s",s+1,t+1);
	int u=0;
	for(int i=2;i<=m;i++){
		while(u&&t[i]!=t[u+1]) u=nxt[u];
		if(t[i]==t[u+1]) u++;
		nxt[i]=u;
	}
	u=0;
	for(int i=0;i<=m;i++) mn[i]=n+1;
	for(int i=1;i<=n;i++){
		while(u&&s[i]!=t[u+1]) u=nxt[u];
		if(s[i]==t[u+1]) u++;
		if(i>=k) mn[u]=min(mn[u],i);
		if(u==m){
			if(k>=m){
				if(max(i,k)<n-k+1){
					printf("Yes\n%d %d\n",max(i-k+1,1),n-k+1);
					return 0;
				}
				if(min(i-m+1,n-k+1)>k){
					printf("Yes\n1 %d\n",min(i-m+1,n-k+1));
					return 0;
				}
			}
			u=nxt[u];
		}
	}
	for(int i=m;i>0;i--) mn[nxt[i]]=min(mn[nxt[i]],mn[i]);
	u=nxt[m]=m+1;
	for(int i=m-1;i>0;i--){
		while(u<=m&&t[i]!=t[u-1]) u=nxt[u];
		if(t[i]==t[u-1]) u--;
		nxt[i]=u;
	}
	u=m+1;
	for(int i=n;i>0;i--){
		while(u<=m&&s[i]!=t[u-1]) u=nxt[u];
		if(s[i]==t[u-1]) u--;
		if(n-i+1>=k) mx[u]=max(mx[u],i);
		if(u==1) u=nxt[u];
	}
	for(int i=1;i<=m;i++) mx[nxt[i]]=max(mx[nxt[i]],mx[i]);
	for(int i=max(m-k,1);i<=min(k,m);i++) if(mn[i]<mx[i+1]){
		printf("Yes\n%d %d\n",mn[i]-k+1,mx[i+1]);
		return 0;
	}
	printf("No\n");
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}