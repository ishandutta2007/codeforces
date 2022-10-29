#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=(int)2e5+9;
int a[N],last[N];
int main() 
{
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,1,n+1)scanf("%d",&a[i]),last[i]=0;
		int ans=N;
		rep(i,1,n+1){
			if(last[a[i]]){
				ans=min(ans,i-last[a[i]]+1);
				last[a[i]]=i;
			}
			else last[a[i]]=i;
		}
		if(ans==N)ans=-1;
		printf("%d\n",ans);
	}
}