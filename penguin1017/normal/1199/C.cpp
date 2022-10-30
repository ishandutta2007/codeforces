#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N (int)4e5+9
using namespace std;
int a[N],sum[N];
int main()
{
	int n,I,tot,x;
	scanf("%d%d",&n,&I);
	x=8*I/n;
	rep(i,0,n)scanf("%d",&a[i]);
	if(x>30){
		cout<<0;
		return 0;
	}
	tot=(1<<x);
	sort(a,a+n);
	int cnt=1,las=a[0];
	sum[1]++;
	rep(i,1,n){
		if(a[i]==las)sum[cnt]++;
		else{
			las=a[i];
			sum[++cnt]=1;
		}
	}
	rep(i,1,cnt+1)sum[i]+=sum[i-1];
	int maxn=0;
	if(tot>=cnt){
		cout<<0;
		return 0;
	}
	rep(i,tot,cnt+1)maxn=max(maxn,sum[i]-sum[i-tot]);
	cout<<n-maxn;
}