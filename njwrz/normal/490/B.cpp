#include <bits/stdc++.h>
using namespace std;
int n,qian[1000005],hou[1000005];
int ans[200005],f[1000005];
int main(){
	int x,y,q=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		qian[y]=x;
		hou[x]=y;
		f[x]++;f[y]+=2;
	}
	int l=0;
	for(int i=2;i<=n;i+=2){
		ans[i]=hou[l];
		l=hou[l];
	}
	for(int i=1;i<=1000000;i++){
		if(f[i]==1){
			l=i;break;
		}
	}
	for(int i=1;i<=n;i+=2){
		ans[i]=l;
		l=hou[l];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}