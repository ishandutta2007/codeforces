#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,q;
int a[MN],tim[MN];
int op[MN],id[MN],val[MN],mx[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	scanf("%d",&q);
	F(i,1,q)scanf("%d",op+i),(op[i]==1?scanf("%d%d",id+i,val+i):scanf("%d",val+i));
	dF(i,q,1)mx[i]=mx[i+1],(op[i]==2?mx[i]=max(mx[i],val[i]):0);
	F(i,1,q)if(op[i]==1)tim[id[i]]=i,a[id[i]]=val[i];
	F(i,1,n)printf("%d ",max(a[i],mx[tim[i]+1]));
	return 0;
}