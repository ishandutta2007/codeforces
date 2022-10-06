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
int n,q,c;
int b[2][MN];
int main(){
	scanf("%d%d",&n,&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y),--x;
		if(b[x][y]){
			c-=b[x^1][y-1]+b[x^1][y]+b[x^1][y+1];
			b[x][y]=0;
		}else{
			c+=b[x^1][y-1]+b[x^1][y]+b[x^1][y+1];
			b[x][y]=1;
		}
		puts(c?"No":"Yes");
	}
	return 0;
}