#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--){
		int n,x,a,b;
		cin>>a>>b;
		if(a==1){
			if(b==1)printf("YES\n");
			else printf("NO\n");
		}
		else if(a==2||a==3){
			if(b<=3)printf("YES\n");
			else printf("NO\n");
		}
		else printf("YES\n");
	}
}