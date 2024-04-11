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
#define mkp make_pair
#define fi first
#define se second
int n,a[MN],b[MN],d[MN],c;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),c=0;
	F(i,1,n)scanf("%1d",a+i);
	b[1]=1;
	F(i,1,n){
		b[i]=a[i]==a[i-1]?b[i-1]+1:1;
		if(i==n||a[i]!=a[i+1])d[++c]=b[i];
	}
//	F(i,1,c)printf("%d,",d[i]);puts("");
	int p=1,q=1,ans=0;
	while(p<=c){
		q=max(q,p);
		while(q<=c&&d[q]==1)++q;
		++ans;
		if(q<=c)--d[q],++p;
		else{ans+=(c-p)/2;break;}
	}
	printf("\t\t%d\n",ans);
}	return 0;
}