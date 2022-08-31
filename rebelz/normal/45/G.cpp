#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n,tot=0;
bool flag[20000005];
int prime[15000005];

void getprime(int n){
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	for(int i=2;i<=n;i++){
		if(flag[i])
			prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			flag[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main(){
	cin>>n;
	int x=n*(n+1)/2;
	getprime(x);
	if(x%2==0){
		for(int i=1;i<=tot&&prime[i]<x;i++){
			if(flag[x-prime[i]]){
				for(int j=1;j<=n;j++){
					if(j==prime[i])
						printf("2 ");
					else
						printf("1 ");
				}
				putchar('\n');
				break;
			}
		}
	}
	else if(flag[x]){
		for(int i=1;i<=n;i++)
			printf("1 ");
		cout<<endl;
	}
	else{
		if(flag[x-2]){
			for(int i=1;i<=n;i++){
				if(i==2)
					printf("2 ");
				else
					printf("1 ");
			}
			putchar('\n');
		}
		else{
			for(int i=2;i<=tot&&prime[i]<x;i++){
				for(int j=1;j<=tot&&j!=i&&prime[i]+prime[j]<x;j++){
					if(flag[x-prime[i]-prime[j]]){
						for(int k=1;k<=n;k++){
							if(k==prime[i])
								printf("2 ");
							else if(k==prime[j])
								printf("3 ");
							else
								printf("1 ");
						}
						putchar('\n');
						return 0;
					}
				}
			}
		}
	}
	return 0;
}