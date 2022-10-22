#include <bits/stdc++.h>
using namespace std;
int da[105],x[105],y[105];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i],da[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((x[i]==x[j]||y[i]==y[j])&&
				da[i]!=da[j]){
				int t1=da[i],t2=da[j];
				for(int k=1;k<=n;k++){
					if(da[k]==t1)da[k]=t2;
				}
			}
		}
	}
	int ans=n-1;
	for(int i=1;i<=n;i++){
		if(da[i]!=i)ans--;
	}
	cout<<ans;
	return 0;
}