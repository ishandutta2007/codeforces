#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(itn i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=0; 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,ans=0,sum;
		scanf("%d%d%d",&a,&b,&c);
		rep(i,0,101)rep(j,0,101){
			if(i<=a&&2*i+j<=b&&2*j<=c){
				ans=max(ans,3*(i+j));
			}
		}
		printf("%d\n",ans);
	}
}