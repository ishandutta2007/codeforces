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
int s[64][64],t[64][64];
char qinc(){
	char s=getchar();
	while(s==' '||s=='\n')s=getchar();
	return s;
}
struct sak{
	int s,x,y;
	bool operator <(sak b){
		return s<b.s;
	}
};
sak a[2505];
int sum,km;
void dfs(int x,int y){
	if(!s[x][y])return;
	++sum;
	s[x][y]=0;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}
void dfs2(int x,int y){
	if(!t[x][y])return;
	t[x][y]=0;
	dfs2(x+1,y);
	dfs2(x-1,y);
	dfs2(x,y-1);
	dfs2(x,y+1);
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    xh(i,1,n)
    	xh(j,1,m){
    		t[i][j]=s[i][j]= qinc()=='.';
		}
	xh(i,1,n){
		dfs(i,1);
		dfs(i,m);
	}
	xh(i,1,m){
		dfs(1,i);
		dfs(n,i);
	}
	xh(i,1,n){
		xh(j,1,m){
			if(s[i][j]){
				sum=0;
				dfs(i,j);
				a[++km].s=sum;
				a[km].x=i;
				a[km].y=j;
			}
		}
	}
	sort(a+1,a+km+1);
	sum=0;
	xh(i,1,km-k){
		dfs2(a[i].x,a[i].y);
		sum+=a[i].s;
	}
	qout(sum);
	putchar('\n');

	xh(i,1,n){
		xh(j,1,m){
			putchar(t[i][j]?'.':'*');
		}
		putchar('\n');
	}
	rt 0;
}