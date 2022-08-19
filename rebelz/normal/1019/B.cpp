#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n;

int ask(int x){
	int t;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	cin>>t;
	return t;
}

int main(){
	cin>>n;
	if((n/2)%2==1){
		cout<<"! "<<-1<<endl;
		return 0;
	}
	int a=ask(1)-ask(1+n/2),b;
	if(a==0){
		cout<<"! "<<1<<endl;
		return 0;
	}
	int l=1,r=n/2;
	while(l<=r){
		int mid=(l+r+1)/2;
		b=ask(mid)-ask(mid+n/2);
		if(b==0){
			cout<<"! "<<mid<<endl;
			return 0;
		}
		if(a>0==b>0){
			a=b;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<"! "<<-1<<endl;
	return 0;
}