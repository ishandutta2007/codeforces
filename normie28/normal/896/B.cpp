#include<bits/stdc++.h>
#define ll long long
using namespace std;
int flag,n,m,mx,i,x,a[2010];
int main(){
    cin>>n>>m>>mx;
	while(m--){
		cin>>x;
		if(x<=mx/2){
			for(i=1;i<=n;i++)if(!a[i]||x<a[i]){
				a[i]=x;
				cout<<i<<endl;break;
			}
		}
		 else{
		 	for(i=n;i;i--)if(!a[i]||x>a[i]){
		 		a[i]=x;
				cout<<i<<endl;break;
			 }
		 }
		flag=0;
		for(i=1;i<=n;i++)if(!a[i]||a[i]<a[i-1]){
			flag=1;break;
		}
		fflush(stdout);
		if(!flag) return 0;
	}
}