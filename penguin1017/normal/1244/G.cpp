#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=(int)1e6+9;
ll tot;
int a[N],b[N],n;
void solve(int p1,int len){
	if(tot>=len){
		tot-=len;
		swap(b[p1],b[p1+len]);
	}
	else{
		swap(b[p1],b[p1+tot]);
		tot=0;
	}
}
int main()
{
	scanf("%d%lld",&n,&tot);
	ll maxn=0;
	rep(i,1,n+1){
		a[i]=i;
		b[i]=n+1-i;
		maxn+=max(a[i],b[i]);
	}
	rep(i,1,n+1)b[i]=i;
	ll mini=1ll*n*(n+1)/2;
	if(tot<mini){
		cout<<-1;
		return 0;
	}
	if(tot>maxn)tot=maxn;
	printf("%lld\n",tot);
	tot-=mini;
	//cout<<tot<<"tot\n";
	int len=n-1;
	rep(i,1,n+1){
		if(tot)solve(i,len);
		else break;
		len-=2;
	}
	rep(i,1,n+1){
		printf("%d",a[i]);
		if(i!=n)printf(" ");
		else printf("\n");
	}
	rep(i,1,n+1){
		printf("%d",b[i]);
		if(i!=n)printf(" ");
		else printf("\n");
	}
}