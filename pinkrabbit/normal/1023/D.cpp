#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,q;
int a[200005],l[200005],r[200005];
int s[200005],t[200005],c[200005];
int b[200005];
int S[200005][21];

int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%d",a+i), b[i]=a[i];
	b[0]=1;
	F(i,1,n) if(!b[i]) b[i]=b[i-1];
	F(i,1,n) S[i][0]=b[i];
	for(int j=1;1<<j<=n;++j) F(i,1,n-(1<<j)+1) S[i][j]=min(S[i][j-1],S[i+(1<<j-1)][j-1]);
	F(i,1,n){
		if(!s[b[i]]) s[b[i]]=i;
		t[b[i]]=i;
	}
	F(i,1,q) if(s[i]){
		int len=t[i]-s[i]+1;
		int L=31-__builtin_clz(len);
		int d=min(S[s[i]][L],S[t[i]-(1<<L)+1][L]);
		if(d<i) return 0*puts("NO");
	}
	int Q=0;
	F(i,1,n) if(b[i]==q) Q=1;
	if(Q){
		puts("YES");
		F(i,1,n) printf("%d ",b[i]);
		return 0;
	}
	int Z=0;
	F(i,1,n) if(a[i]==0) Z=i;
	if(!Z) return 0*puts("NO");
	puts("YES"); b[Z]=q;
	F(i,1,n) printf("%d ",b[i]);
	return 0;
}