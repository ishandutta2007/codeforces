#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1e6+55;
char l[N],r[N];
int n,m;
int a[N],b[N];
bool check(){
	if(n<2)return 0;
	int qz=0;
	for(int i=1;i<=n;i++){
		a[i]=l[i]-'0';
		b[i]=r[i]-'0';
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			for(i++;i<=n;i++){
				if(a[i]!=1 || b[i]!=0){
					return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	scanf("%s",l+1);
	scanf("%s",r+1);
	if(l[1]=='0' and r[1]=='1'){
		for(int i=1;i<=n;i++){
			printf("1");
		}
		return 0;
	}
	if(r[n]=='1'){
		for(int i=1;i<=n;i++){
			printf("%c",r[i]);
		}
		return 0;
	}
	if(r[n]=='0'){
		if(!check()){
			for(int i=1;i<=n;i++){
				printf("%c",r[i]);
			}
		}
		else{
			for(int i=1;i<n;i++){
				printf("%c",r[i]);
			}
			printf("1");
		}
	}
	return 0;
}