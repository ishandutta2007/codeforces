#include <bits/stdc++.h>
using namespace std;
int main(){
	int last,n,m,t,ans=0,l,p,x,y;
	cin>>n>>m;x=n,y=m;
	n--;
	last=1;
	t=0;l=n+m;p=2;
	for(int i=1;i<=l;i++){
		if(p==1){
			if((last==1&&n>0)||m==0){
				n--;t++;last=1;
			}else {
				if(last==2)t++;
				m--,last=2;
			}
		}else{
			if((last==2&&n>0)||m==0){
				if(last==1)t++;
				n--;last=1;
			}else {
				if(last==2)t++;
				last=2;m--;
			}
		}
		p=3-p;
	}
	ans=t;t=0;
	n=x;m=y-1;last=2;p=2;
	for(int i=1;i<=l;i++){
		if(p==1){
			if((last==1&&n>0)||m==0){
				n--;t++;last=1;
			}else {
				if(last==2)t++;
				m--,last=2;
			}
		}else{
			if((last==2&&n>0)||m==0){
				if(last==1)t++;
				n--;last=1;
			}else {
				if(last==2)t++;
				last=2;m--;
			}
		}
		p=3-p;
	}
	cout<<max(t,ans)<<' '<<x+y-1-max(t,ans);
	return 0;
}