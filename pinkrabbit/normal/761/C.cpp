#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#define For(i,a,b) for(int i=a;i<=(b);++i)
#define Ford(i,a,b) for(int i=a;i>=(b);--i)
#define For2(i,a,b) for(int i=a;i<(b);++i)
#define Ford2(i,a,b) for(int i=a;i>(b);--i)
using namespace std;
int n,m;
char str[51];
int a[51][3];
int Ans=999999;
void init(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%s",str);
		a[i][0]=a[i][1]=a[i][2]=999999;
		For2(j,0,m){
			if('a'<=str[j]&&str[j]<='z')a[i][0]=min(a[i][0],min(j,m-j));
			else if('0'<=str[j]&&str[j]<='9')a[i][1]=min(a[i][1],min(j,m-j));
			else a[i][2]=min(a[i][2],min(j,m-j));
		}
	}
}
int main(){
	init();
	For(i,1,n){
		For(j,1,n){
			if(j==i)continue;
			For(k,1,n){
				if(k==i||k==i)continue;
				Ans=min(Ans,a[i][0]+a[j][1]+a[k][2]);
			}
		}
	}
	printf("%d",Ans);
	return 0;
}