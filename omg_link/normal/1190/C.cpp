#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MN 100000
int n,k,min0,max0,min1,max1;
int ls[MN+5][2],nx[MN+5][2];
char s[MN+5];
void win1(){
	puts("tokitsukaze");
	exit(0);
}
void win2(){
	puts("quailty");
	exit(0);
}
void draw(){
	puts("once again");
	exit(0);
}
int main(){
	scanf("%d%d%s",&n,&k,&s[1]);
	min0=min1=n+1;
	max0=max1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			min0=std::min(min0,i);
			max0=std::max(max0,i);
		}else{
			min1=std::min(min1,i);
			max1=std::max(max1,i);
		}
	}
	for(int i=1,ls0=0,ls1=0;i<=n;i++){
		ls[i][0]=ls0;
		ls[i][1]=ls1;
		if(s[i]=='0') ls0=i;
		else ls1=i;
	}
	for(int i=n,nx0=n+1,nx1=n+1;i>=1;i--){
		nx[i][0]=nx0;
		nx[i][1]=nx1;
		if(s[i]=='0') nx0=i;
		else nx1=i;
	}
	if(max0==0||max1==0) win1();
	if(k==n) win1();
	if(max0-min0+1<=k) win1();
	if(max1-min1+1<=k) win1();
	bool ok=true;
	for(int i=1;i<=n-k;i++){
		//paint 0
		if(std::max(i,max0)-std::min(i,min0)+1>k){ //check 0
			int mx1,mi1;
			if(max1<=i+k-1) mx1=ls[i][1];
			else mx1=max1;
			if(min1>=i) mi1=nx[i+k-1][1];
			else mi1=min1;
			if(mx1-mi1+1>k){
				ok=false;
			}
		}
		//paint 1
		if(std::max(i,max1)-std::min(i,min1)+1>k){ //check 1
			int mx0,mi0;
			if(max0<=i+k-1) mx0=ls[i][0];
			else mx0=max0;
			if(min0>=i) mi0=nx[i+k-1][0];
			else mi0=min0;
			if(mx0-mi0+1>k){
				ok=false;
			}
		}
	}
	if(ok) win2();
	draw();
}