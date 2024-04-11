#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001];
int main(){
	int n,m,x,t;
	cin>>n>>m>>x>>t;
	int i;
	for(i=0;i<t;i++)cin>>a[i]>>b[i];
	for(i=0;i<t;i++){
		if(a[i]){
			n++;
			if(b[i]<=m)m++;
		}else{
			if(b[i]>=m){
				n=b[i];
			}else{
				n-=b[i];m-=b[i];
			}
		}
		cout<<n<<" "<<m<<endl;
	}
	return 0;
}