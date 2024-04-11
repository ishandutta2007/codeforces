#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int> a[5005];
int main(){
	int ans=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].f>>a[i].s;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].s>=ans){
			ans=a[i].s;
		}else ans=a[i].f;
	}
	cout<<ans;
	return 0;
}