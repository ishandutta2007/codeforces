#include<bits/stdc++.h>
using namespace std;
int T;
const int N=105;
int a[N],n,tong[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int maxx=0;
		memset(tong,0,sizeof(tong));
		for(int i=1;i<=n;i++)cin>>a[i],tong[a[i]]++,maxx=max(maxx,tong[a[i]]);
		cout<<maxx<<endl;
	}
	return 0;
}