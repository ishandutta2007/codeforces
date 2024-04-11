#include <bits/stdc++.h>
using namespace std;
int main(){
	int st,en,d,t,p,ans=0,lj=0,ans1,t1,t2;
	cin>>st>>en>>t>>d;t1=st;t2=en;
	if(d==0){
		cout<<t*st;return 0;
	}
	for(int i=1;i<=t;i++){
		lj+=st;
		if(st>=en){
			p=(st-en+d-1)/d;
			if(p<=t-i){
				ans1=lj;int f=0;
				for(int j=en;j<st;j+=d){
					ans1+=j;f++;
				}
				ans1+=st*(t-i-f);
				ans=max(ans,ans1);
			}
		}
		st+=d;
	}
	lj=0;
	st=t2;en=t1;
	for(int i=1;i<=t;i++){
		lj+=st;
		if(st>=en){
			p=(st-en+d-1)/d;
			if(p<=t-i){
				ans1=lj;int f=0;
				for(int j=en;j<st;j+=d){
					ans1+=j;f++;
				}
				ans1+=st*(t-i-f);
				ans=max(ans,ans1);
			}
		}
		st+=d;
	}
	cout<<ans;
	return 0;
}