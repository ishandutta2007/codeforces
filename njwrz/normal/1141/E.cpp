#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long n,m,a[200005],t=0,maxi=0,ans;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];a[i]=-a[i];
		t+=a[i];maxi=max(maxi,t);
	}
	if(maxi<m&&t<=0){
		cout<<"-1";return 0;
	}
	m-=maxi;
	if(m<=0){
		t=0;m+=maxi;
		for(int i=0;i<n;i++){
			t+=a[i];
			if(t>=m){
				cout<<i+1;return 0; 
			}
		}
	}
	ans=(m/t)+(m%t!=0);
	t=ans*t;m+=maxi;
	for(int i=0;i<n;i++){
		t+=a[i];
		if(t>=m){
			cout<<ans*n+i+1;return 0;
		}
	}
	return 0;
}