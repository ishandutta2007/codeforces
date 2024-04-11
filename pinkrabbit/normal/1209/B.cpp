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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,s;
int a[MN],b[MN],c[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%1d",c+i),s+=c[i];
	F(i,1,n)scanf("%d%d",a+i,b+i);
	F(j,1,1000){
		F(i,1,n)if(j>=b[i]&&j%a[i]==b[i]%a[i])c[i]^=1;
		int t=0;
		F(i,1,n)t+=c[i];
		s=max(s,t);
	}
	printf("%d\n",s);
	return 0;
}