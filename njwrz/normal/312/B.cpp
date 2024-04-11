#include<bits/stdc++.h>
using namespace std;
int main(){
	double n1,m1,n2,m2,s=1,ans=0;
	int i;
	cin>>n1>>m1>>n2>>m2;
	for(i=0;i<100000;i++){
		ans+=s*n1/m1;
		s*=(1-n1/m1)*(1-n2/m2);
	}
	printf("%.12f",ans);
	return 0;
}