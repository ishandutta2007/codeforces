#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%s",&n,s+1);
	F(i,1,n)s[i+n]=s[i];
	int o1=0,o2=0;
	F(i,1,n){
		if(s[i]=='<')o1=1;
		if(s[i]=='>')o2=1;
	}
	if(o1&&o2){
		int ans=0;
		F(i,1,n)
			if(s[i]=='-'||s[i+1]=='-')
				++ans;
		printf("%d\n",ans);
	}else{
		printf("%d\n",n);
	}
}	return 0;
}