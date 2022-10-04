#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline void qw(int&X){scanf("%d",&X);}
inline void qw(int&X,int&Y){scanf("%d%d",&X,&Y);}
inline void qw(int&X,int&Y,int&Z){scanf("%d%d%d",&X,&Y,&Z);}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
char str[1003];
int cnt;
int main(){
	scanf("%s",str);
	int len=strlen(str);
	F2(i,0,len){
		if(str[i]=='a') ++cnt;
		if(str[i]=='e') ++cnt;
		if(str[i]=='i') ++cnt;
		if(str[i]=='o') ++cnt;
		if(str[i]=='u') ++cnt;
		if(str[i]=='1') ++cnt;
		if(str[i]=='3') ++cnt;
		if(str[i]=='5') ++cnt;
		if(str[i]=='7') ++cnt;
		if(str[i]=='9') ++cnt;
	}
	printf("%d",cnt);
	return 0;
}