#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<pii> 
#define fi first
#define se second
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e5+9;
vi g[N];
bitset<100009> a[2];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--){
		int op,pos;
		scanf("%d%d",&op,&pos);
		a[op-1][pos]=a[op-1][pos]^1;
		if((a[0]&a[1]).any())printf("NO\n");
		else if((a[0]>>1&a[1]).any())printf("NO\n");
		else if((a[0]<<1&a[1]).any())printf("NO\n");
		else printf("YES\n");
	}
}