#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
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
int op[MN],val[MN];
int stk[MN],tp;
int ans[MN];
int main(){
	scanf("%d",&n);
	int prefix=0;
	F(i,1,2*n){
		char str[3];
		scanf("%s",str);
		if(*str=='+'){
			op[i]=1;
			++prefix;
		}else{
			op[i]=2;
			scanf("%d",&val[i]);
			--prefix;
		}
		if(prefix<0){
			puts("NO");
			return 0;
		}
	}
	int c=0;
	F(i,1,2*n){
		if(op[i]==1){
			stk[++tp]=++c;
		}else{
			ans[stk[tp--]]=val[i];
		}
	}
	c=0;
	priority_queue<int,vector<int>,greater<int>>pq;
	F(i,1,2*n){
		if(op[i]==1){
			pq.push(ans[++c]);
		}else{
			int x=pq.top();
			pq.pop();
			if(x!=val[i])return puts("NO"),0;
		}
	}
	puts("YES");
	F(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}