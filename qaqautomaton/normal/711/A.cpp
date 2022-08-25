#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<string>
#define xh(a,b,c) for(int a=(b),End=(c);a<=End;++a)
#define dxh(a,b,c) for(int a=(b),End=(c);a>=End;--a)
#define hy(a)memset(a,0,sizeof(a))
#define sqr(a) (a)*(a)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define rt return
#define js exit(0)
#define gc() getchar()
#define pc(x) putchar(x)
#define opwrite(x) freopen(x,"w",stdout);
#define opread(x) freopen(x,"r",stdin);
#define clwrite fclose(stdout)
#define clread fclose(stdin)

using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ul;
typedef pair<int,int> lix;
void qin(int &x){
	int base=1,num;
	char c=gc();
	while(!(c=='-'||c>='0'&&c<='9'||c==EOF))c=getchar();
	if(c==EOF)exit(0);
	if(c=='-')base=-1,c=gc();
	num=c-'0';
	c=gc();
	while(c>='0'&&c<='9'){
		num*=10;
		num+=c-'0';
		c=gc();
	}
	x=num*base;
}
char integ[50];
void qout(int x){
	if(x<0)pc('-'),x=-x;
	int len=0;
	do{
		integ[len++]=x%10+'0';
		x/=10;
	}while(x);

	while(len--){
		pc(integ[len]);
	}
}

void out(int n){
	qout(n);
	putchar('\n');
}
char s[1250][10];
void pr(int n){
	puts("YES");
	xh(i,1,n)puts(s[i]);
	js; 
}
int main(){
	int n;
	scanf("%d\n",&n);
	xh(i,1,n){
		gets(s[i]);
	}
	xh(i,1,n){
		if(s[i][0]=='O'&&s[i][1]=='O'){
			s[i][0]=s[i][1]='+';
			pr(n);
		}
		if(s[i][3]=='O'&&s[i][4]=='O'){
			s[i][3]=s[i][4]='+';
			pr(n);
		}
	}
	puts("NO");
    rt 0;
}