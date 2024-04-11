#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a%10>b%10;
}
int main(){
	int n,m,a[100005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i]/10;
	sort(a+1,a+n+1,cmp);
	int t=0;
	for(int i=1;i<=n;i++){
		if(a[i]%10!=0&&m>=10-a[i]%10){
			m-=10-a[i]%10;
			ans++;
		}
		t+=(100-a[i])/10;
	}
	cout<<ans+min(t,m/10);
	return 0;
}