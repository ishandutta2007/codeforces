#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
	int id,x;
	bool operator<(const node c)const{
		return x<c.x;
	}
}k[200005];

int n,pos1,pos2;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i].x;
		k[i].id=i;
	}
	sort(k+1,k+n+1);
	pos1=pos2=n;
	for(int i=1;i<=n;i++){
		if(k[i].x>=0){
			pos1=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(k[i].x>0){
			pos2=i-1;
			break;
		}
	}
	if(pos1==0&&pos2==n){
		for(int i=1;i<=n-1;i++)
			cout<<1<<' '<<i<<' '<<i+1<<endl;
		return 0;
	}
	if(pos1%2==0){
		for(int i=1;i<=pos1-1;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
		for(int i=pos1+1;i<=pos2-1;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
		if(k[pos2].x==0&&pos2>0)
			cout<<2<<' '<<k[pos2].id<<endl;
		if(pos2!=n&&pos1!=0)
			cout<<1<<' '<<k[pos1].id<<' '<<k[pos2+1].id<<endl;
		for(int i=pos2+1;i<=n-1;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
	}
	else{
		for(int i=1;i<=pos1-2;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
		for(int i=pos1+1;i<=pos2-1;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
		if(k[pos2].x==0){
			cout<<1<<' '<<k[pos1].id<<' '<<k[pos2].id<<endl;
			if(pos1!=1||pos2!=n)
				cout<<2<<' '<<k[pos2].id<<endl;
		}
		else
			cout<<2<<' '<<k[pos1].id<<endl;
		if(pos2!=n&&pos1!=1)
			cout<<1<<' '<<k[pos1-1].id<<' '<<k[pos2+1].id<<endl;
		for(int i=pos2+1;i<=n-1;i++)
			cout<<1<<' '<<k[i].id<<' '<<k[i+1].id<<endl;
	}
	return 0;
}