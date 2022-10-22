#include <bits/stdc++.h>
using namespace std;
char a[300005];
int main(){
	int n,m,l;char c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]=='.'&&a[i-1]=='.')ans++;
	}
	for(int i=0;i<m;i++){
		cin>>l>>c;
		if(c=='.'){
			if(a[l]!='.'){
				ans+=(a[l-1]=='.')+(a[l+1]=='.');
			}
		}else{
			if(a[l]=='.'){
				ans-=(a[l-1]=='.')+(a[l+1]=='.');
			}
		}
		a[l]=c;
		cout<<ans<<'\n';
	}
	return 0;
}