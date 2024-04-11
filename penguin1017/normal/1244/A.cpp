#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int ans1=a/c;
		if(a%c)ans1++;
		int ans2=k-ans1;
		if(ans2*d>=b){
			printf("%d %d\n",ans1,ans2);
		}
		else printf("-1\n");
	}
 }