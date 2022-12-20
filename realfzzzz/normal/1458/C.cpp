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
const int maxn=1e3+5,maxm=1e5+5;
int n,m,a[maxn][maxn],b[maxn][maxn];
char s[maxm];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) a[i][j]=read()-1;
		scanf("%s",s+1);
		int p[3],t[3];
		for(int i=0;i<3;i++){
			p[i]=i;
			t[i]=0;
		}
		for(int i=1;i<=m;i++)
			if(s[i]=='R') t[1]=(t[1]+1)%n;
			else if(s[i]=='L') t[1]=(t[1]-1+n)%n;
			else if(s[i]=='D') t[0]=(t[0]+1)%n;
			else if(s[i]=='U') t[0]=(t[0]-1+n)%n;
			else if(s[i]=='I'){
				swap(p[1],p[2]);
				swap(t[1],t[2]);
			}
			else{
				swap(p[0],p[2]);
				swap(t[0],t[2]);
			}
		for(int i=0;i<n;i++) for(int j=0;j<n;j++){
			int x[3]={i,j,a[i][j]};
			b[(x[p[0]]+t[0])%n][(x[p[1]]+t[1])%n]=(x[p[2]]+t[2])%n;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) printf("%d ",b[i][j]+1);
			printf("\n");
		}
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}