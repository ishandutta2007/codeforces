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
char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1);
	int ans=10;
	{
		int now=10;
		int a=0,b=0;
		F(i,1,10){
			if(s[i]=='1')++(i&1?a:b);
			else if(s[i]=='?'){
				if(i&1)
					++a;
			}
			int lef=(11-i)/2;
			if(b+lef<a){
				now=i;
				break;
			}
		}
		ans=min(ans,now);
	}
	{
		int now=10;
		int a=0,b=0;
		F(i,1,10){
			if(s[i]=='1')++(i&1?a:b);
			else if(s[i]=='?'){
				if(~i&1)
					++b;
			}
			int lef=(10-i)/2;
			if(a+lef<b){
				now=i;
				break;
			}
		}
		ans=min(ans,now);
	}
	printf("%d\n",ans);
}	return 0;
}