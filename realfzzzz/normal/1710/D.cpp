#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n;
char s[maxn][maxn];
int l[maxn],r[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+i);
		for(int i=1;i<=n;i++) l[i]=r[i]=i;
		for(int i=1;i<=n;i++) for(int j=1;j<=n-i+1;j++)
			if(s[j][j+i-1]=='1'&&r[j]!=r[j+i-1]){
				int x=j+i-1;
				printf("%d %d\n",j,x);
				int u=r[j]+1,p0=x,p1=j;
				for(bool k=0;u<l[x];k^=1){
					if(k){
						printf("%d %d\n",u,p1);
						p1=u;
					}
					else{
						printf("%d %d\n",u,p0);
						p0=u;
					}
					u=r[u]+1;
				}
				for(int k=l[j];k<=r[x];k++){
					l[k]=l[j];
					r[k]=r[x];
				}
			}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}