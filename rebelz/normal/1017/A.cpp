#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
	int s,id;
	bool operator<(const node c)const{
		if(s==c.s)
			return id<c.id;
		return s>c.s;
	}
}k[1005];

int n;

int main(){
	cin>>n;
	int a,b,c,d;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c>>d;
		k[i].s=a+b+c+d,k[i].id=i;
	}
	sort(k+1,k+n+1);
	for(int i=1;i<=n;i++)
		if(k[i].id==1){
			cout<<i<<endl;
			return 0;
		}
	return 0;
}