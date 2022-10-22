#include <bits/stdc++.h>
using namespace std;
int a[150005],f[150005],ans[150005];
int main(){
	int n,ans1=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],f[a[i]]++;
	for(int i=1;i<=150000;i++){
		if(f[i]&&i!=1&&ans[i-1]==0){
			ans[i-1]=1;f[i]--;ans1++;
		}
		if(f[i]&&ans[i]==0){
			ans[i]=1;f[i]--;ans1++;
		}
		if(f[i]&&ans[i+1]==0){
			ans[i+1]=1;f[i]--;ans1++;
		}
	}
	cout<<ans1;
	return 0;
}