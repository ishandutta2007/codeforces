#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int m,n;
int flag[100005];

int main(){
	cin>>m>>n;
	int x;
	for(int i=1;i<=n;i++){
		cout<<1<<endl;
		fflush(stdout);
		cin>>x;
		if(x==0)
			exit(0);
		flag[i]=x;
	}
	int l=1,r=m,cnt=0;
	while(l<=r){
		int mid=(l+r)/2;
		cnt++;
		cout<<mid<<endl;
		fflush(stdout);
		cin>>x;
		if(x==0)
			exit(0);
		if(x*flag[(cnt-1)%n+1]==1)
			l=mid+1;
		else
			r=mid-1;
	}
	return 0;
}