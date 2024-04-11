#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 400005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,k,ans;
int a[MN],b[MN],c[MN];
int main(){
	scanf("%d%d",&n,&k),k*=8,k/=n;
	if(k<=20)k=min(1<<k,n);
	else k=n;
	F(i,1,n)scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	F(i,1,n)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	F(i,1,n)++c[a[i]];
	F(i,1,m)c[i]+=c[i-1];
	k=min(k,m);
	F(i,k,m)ans=max(ans,c[i]-c[i-k]);
	printf("%d\n",n-ans);
	return 0;
}