#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<complex>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#define xh(a,b,c) for(int a=(b),ITISEND=(c);a<=ITISEND;++a)
#define dxh(a,b,c) for(int a=(b),ITISEND=(c);a>=ITISEND;--a)

#define hy(a) memset(a,0,sizeof(a))
#define bl(a,b)for(int a=beg[b];a;a=ne[a])
#define sqr(a) ((a)*(a))
#define rt return
#define js exit(0)
#define abs(a) (a<0?-a:a)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
void qin(int &a){
	char ch=getchar();
	int base=1,num=0;
	while(!(ch=='-'||ch==EOF||ch>='0'&&ch<='9'))ch=getchar();
	if(ch==EOF)js;
	if(ch=='-'){
		base=-1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
    }
    a=num*base;
}
char integ[55];
void qout(int a){
	int len=0;
	if(a<0){
		putchar('-');
		a=-a;
	}
	do{
		integ[len++]=a%10+'0';
		a/=10;
	}while(a);
	while(len--)putchar(integ[len]);
}
char c;
char qinc(){
	char s=getchar();
	while(s==' '&&s=='\n')s=getchar();
	return s;
}
int main(){
	int n,kh=0,ans1=0,ans2=0,no=0;
	qin(n);
	xh(i,1,n){
		c=qinc();
		if(c>='a'&&c<='z'||c>='A'&&c<='Z'){
			++no;
		}else{
			if(no){
			if(kh)++ans1;
			else Max(ans2,no);
			no=0;
			}
			
		}
		if(c=='(')kh=1;
		if(c==')')kh=0;
	}
	if(no)Max(ans2,no);
	
	printf("%d %d\n",ans2,ans1);
	rt 0;
}