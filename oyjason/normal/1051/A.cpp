#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
char ch[10000];
int n;
void opt(){for(int i=0;i<n;i++) putchar(ch[i]);putchar('\n');}
int main(){
	for(int T=read();T;T--){
		scanf("%s",ch),n=strlen(ch);
		int t1=0,t2=0,t3=0;
		for(int now=0;now<n;now++){
			if(ch[now]>='a'&&ch[now]<='z') t1++;
			else if(ch[now]>='A'&&ch[now]<='Z') t2++;
			else if(ch[now]>='0'&&ch[now]<='9') t3++;
		}
		if(t1&&t2&&!t3){
			if(t1==1){int now=0;while(ch[now]>='a'&&ch[now]<='z') now++;ch[now]='0';opt();continue;}
			if(t2==1){int now=0;while(ch[now]>='A'&&ch[now]<='Z') now++;ch[now]='0';opt();continue;}
			ch[0]='0';
		}
		if(t1&&!t2&&t3){
			if(t1==1){int now=0;while(ch[now]>='a'&&ch[now]<='z') now++;ch[now]='A';opt();continue;}
			if(t3==1){int now=0;while(ch[now]>='0'&&ch[now]<='9') now++;ch[now]='A';opt();continue;}
			ch[0]='A';
		}
		if(!t1&&t2&&t3){
			if(t2==1){int now=0;while(ch[now]>='A'&&ch[now]<='Z') now++;ch[now]='a';opt();continue;}
			if(t3==1){int now=0;while(ch[now]>='0'&&ch[now]<='9') now++;ch[now]='a';opt();continue;}
			ch[0]='a';
		}
		if(t1&&!t2&&!t3) ch[0]='A',ch[1]='0';
		if(!t1&&t2&&!t3) ch[0]='a',ch[1]='0';
		if(!t1&&!t2&&t3) ch[0]='a',ch[1]='A';
		opt();
	}
}