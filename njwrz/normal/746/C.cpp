#include <bits/stdc++.h>
using namespace std;
int main(){
	int s,x1,x2,t1,t2,m,p,d,mini;
	cin>>s>>x1>>x2;
	cin>>t1>>t2;
	cin>>p>>d;
	mini=abs(x1-x2)*t2;
	bool f=0;m=0;
	while(1){
		if(abs(x1-p)*t2<=m)f=1;
		if(p==x2&&f){
			cout<<min(mini,m);return 0;
		}
		if(p==0){
			d=1;
		}
		if(p==s){
			d=-1;
		}
		p+=d;m+=t1;
	}
	return 0;
}