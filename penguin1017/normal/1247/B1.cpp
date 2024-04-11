#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=105;
int a[N],sum[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,d;
		scanf("%d%d%d",&n,&k,&d);
		rep(i,0,n)scanf("%d",&a[i]);
		int ans=100000;
		rep(i,0,n-d+1){
			memset(sum,0,sizeof(sum));
			rep(j,i,i+d){
				sum[a[j]]++;
			//	cout<<a[j]<<"aaa\n";
			}
			int tot=0;
			rep(j,1,N)if(sum[j])tot++;
		//	cout<<tot<<"tot\n";
			ans=min(ans,tot);
		}
		printf("%d\n",ans);
	} 
}