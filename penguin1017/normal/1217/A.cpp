#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x)) 
#define pb push_back
using namespace std;
int main()
{
	int str,in,ex;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&str,&in,&ex);
		int sum=str+in+ex;
		sum=(sum-1)/2;
		int ans=sum-in+1;
		if(ans<0)ans=0;
		ans=min(ans,ex+1);
		printf("%d\n",ans); 
	}
}