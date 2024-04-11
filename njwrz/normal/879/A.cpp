#include <bits/stdc++.h>
using namespace std;
int main(){
	int t=1,n,x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(t<=x){
			t=x+1;
		}else{
			t-=x;
			t=t/y*y+(t%y!=0)*y+1;
			t+=x;
		}
	}
	cout<<t-1;
	return 0;
}