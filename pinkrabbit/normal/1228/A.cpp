#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
int fff(int x){
	int s[10];
	F(i,0,9)s[i]=0;
	int b=0;
	while(x)s[x%10]=1,x/=10,++b;
	int a=0;
	F(i,0,9)a+=s[i];
	if(a==b)return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	F(i,n,m)if(fff(i))return printf("%d\n",i),0;
	printf("-1");
	return 0;
}