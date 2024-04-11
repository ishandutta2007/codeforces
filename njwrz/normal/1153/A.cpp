#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,ans=1,wait=1000000000;
	cin>>n>>m;int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x>=m){
			if(x-m<wait){
				wait=x-m;ans=i+1;
			}
		}else{
			int t=x%y,s=m;
			while(s%y!=t)s=s+1;
			if(s-m<wait){
				wait=s-m;ans=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}