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
const int maxn=1e3+5;
int n,k;
char a[maxn][maxn];
int c[maxn*2];
void work1(int x,int k){
	c[n+x]++;
	while(c[n+x]<=n-x&&(c[n+x]<k||a[c[n+x]][c[n+x]+x]=='1')){
		a[c[n+x]][c[n+x]+x]='1';
		c[n+x]++;
	}
}
void work2(int x,int k){
	c[n-x]++;
	while(c[n-x]<=n-x&&(c[n-x]<k||a[c[n-x]+x][c[n-x]]=='1')){
		a[c[n-x]+x][c[n-x]]='1';
		c[n-x]++;
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			for(int j=1;j<=n;j++)
				a[i][j]=a[i][j]=='1'?'0':'1';
		}
		for(int i=0;i<=n*2;i++) c[i]=0;
		for(int i=1;i<=n-k+1;i++){
			work1(0,max(c[n-1]+1,c[n+1]+1));
			for(int j=1;j<=n-k-i+1;j++)
				work1(j,max(c[n+j-1],c[n+j+1]+1));
			for(int j=1;j<=n-k-i+1;j++)
				work2(j,max(c[n-j+1],c[n-j-1]+1));
		}
		bool flag=1;
		for(int i=0;i<n;i++){
			flag&=c[n+i]<=n-i;
			work1(i,n-i+1);
		}
		for(int i=1;i<n;i++){
			flag&=c[n-i]<=n-i;
			work2(i,n-i+1);
		}
		if(flag){
			printf("YES\n");
			for(int i=1;i<=n;i++) printf("%s\n",a[i]+1);
		}
		else printf("NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}