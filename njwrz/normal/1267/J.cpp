#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=0;
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	int mini=100000000;
	vector<int> v;
	v.clear();
	for(int i=1;i<=n;i++){
		if(a[i]!=0)mini=min(mini,a[i]),v.push_back(a[i]);
	}
	int ans=mini+1;
	while(1){
		int f=1,t,s,re=0;
		for(int i=0;i<v.size();i++){
			t=v[i]/ans*ans+(v[i]%ans!=0)*ans,s=v[i]/ans+(v[i]%ans!=0);
			if(t-v[i]>s){
				f=0;break;
			}
			re+=s;
		}
		if(f){
			printf("%d\n",re);break;
		}
		ans--;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}