#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 200005
int n,k,ans;
char b[MN],s[3][MN];
const char a[]={'R','G','B'};
int t[3][MN];
int main(){
	int q;scanf("%d",&q);
	while(q--){
		scanf("%d%d%s",&n,&k,b+1),ans=n;
		F(j,0,2){F(i,1,n)s[j][i]=a[(i+j)%3];s[j][n+1]='\0';}
		F(j,0,2)F(i,1,n)t[j][i]=t[j][i-1]+(b[i]!=s[j][i]);
		F(j,0,2)F(i,k,n)ans=min(ans,t[j][i]-t[j][i-k]);
		printf("%d\n",ans);
	}
	return 0;
}