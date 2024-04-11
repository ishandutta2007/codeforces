#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 3000005
#define MM 3000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k,p[MN];
char s[MN],str2[MN];
void solve(char*str,int n){
	for(int i=1;i<=n*2+1;++i)str2[i]='#';
	for(int i=1;i<=n;++i)
		str2[i<<1]=str[i];
	n=n<<1|1;
	str2[n+1]='\0';
//	printf("DD:%s\n",str2+1);
	int mpi=2; p[1]=1; p[2]=2;
	for(int i=3,j;i<=n;++i){
		j=(mpi<<1)-i;
		p[i]=0;
		if(j-p[j]<=mpi-p[mpi]){
			p[i]=mpi+p[mpi]-i;
			while(0<i-p[i]&&i+p[i]<=n&&str2[i-p[i]]==str2[i+p[i]]) ++p[i];
			mpi=i;
		}
		else p[i]=p[j];
	}
	int Ans=0,ansi=0;
	F(i,1,n)if(p[i]==i&&Ans<p[i])Ans=p[i],ansi=i;
	F(i,1,n)if(p[i]==n-i+1&&Ans<p[i])Ans=p[i],ansi=i;
	F(i,ansi-Ans+1,ansi+Ans-1)if(str2[i]!='#')printf("%c",str2[i]);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	int i=1,j=n;
	while(i<j&&s[i]==s[j])++i,--j;
//	printf("[%d-%d]\n",i,j);
	F(k,1,i-1)printf("%c",s[k]);
	solve(s+i-1,j-i+1);
	F(k,j+1,n)printf("%c",s[k]);
	puts("");
}	return 0;
}