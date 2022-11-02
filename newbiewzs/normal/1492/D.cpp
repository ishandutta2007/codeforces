#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int a,b,k;
int main(){
	scanf("%d%d%d",&a,&b,&k);
	swap(a,b);
	if(k>a+b-2 and b){
		cout<<"NO";
		return 0;
	}
	if(!b){
		if(k){
			cout<<"NO";
			return 0;
		}
		else{
			puts("YES");
			for(int i=1;i<=a;i++){
				printf("1");
			}
			puts("");
			for(int i=1;i<=a;i++){
				printf("1");
			}
			return 0;
		}
	}
	if(a==1){
		if(!k){
			puts("YES");
			for(int i=1;i<=a;i++){
				printf("1");
			}
			for(int i=1;i<=b;i++)printf("0");
			puts("");
			for(int i=1;i<=a;i++){
				printf("1");
			}
			for(int i=1;i<=b;i++)printf("0");
			return 0;
		}
		else{
			cout<<"NO";
			return 0;
		}
	}
	if(!k){
		puts("YES");
		for(int i=1;i<=a;i++){
			printf("1");
		}
		for(int i=1;i<=b;i++)printf("0");
		puts("");
		for(int i=1;i<=a;i++){
			printf("1");
		}
		for(int i=1;i<=b;i++)printf("0");
		return 0;
	}
	if(k>=a-1){
		puts("Yes");
		for(int i=1;i<=a;i++)printf("1");
		for(int i=1;i<=b;i++)printf("0");
		puts("");
		printf("10");
		for(int i=3;i<=a;i++)printf("1");
		int top=a-2;
		for(int i=1;i<=b;i++){
			top++;
			if(top==k)printf("1");
			else printf("0");
		}
		return 0;
	}
	puts("YES");
	for(int i=1;i<=a;i++)printf("1");
	for(int i=1;i<=b;i++)printf("0");
	puts("");
	int pos=a-k+1;
	for(int i=1;i<pos;i++)printf("1");
	printf("0");
	for(int i=pos+1;i<=a+1;i++)printf("1");
	for(int i=2;i<=b;i++)printf("0");
	return 0;
}