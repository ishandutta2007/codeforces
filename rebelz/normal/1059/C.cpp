#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n;

void work(int x,int p){
	if(x==3)
		printf("%d %d %d\n",p,p,3*p);
	else if(x==2)
		printf("%d %d\n",p,2*p);
	else if(x==1)
		printf("%d\n",p);
	else{
		for(int i=1;i<=(x+1)/2;i++)
			printf("%d ",p);
		work(x-(x+1)/2,p*2);
	}
}

int main(){
	cin>>n;
	work(n,1);
	return 0;
}