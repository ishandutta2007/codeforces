#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=(int)1e3+9;
char s[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		scanf("%s",s);
		int ans,tot=0;
		rep(i,0,n)if(s[i]=='1')tot++;
		ans=n+tot;
	//	cout<<ans<<"ans1\n";
		rep(i,0,n){
			if('1'==s[i]){
				ans=max(ans,2*(n-i));
				break;
			}
		}
	//	cout<<ans<<"ans2\n";
		per(i,0,n){
			if(s[i]=='1'){
				ans=max(ans,2*(i+1));
				break;
			}
		}
	//	cout<<ans<<"ans3\n";
		printf("%d\n",ans);
	}
}