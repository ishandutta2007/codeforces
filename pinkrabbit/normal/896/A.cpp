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
int n,q;
ll k;
char str[200]=" What are you doing at the end of the world? Are you busy? Will you save us?";
char str2[200]=" What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
int a1,a2;
ll a[100001];
int Maxsa;
void clac(){
	a[0]=a1;
	a[1]=a2+a[0]+a[0];
	F(i,2,100000){
		a[i]=a2+a[i-1]+a[i-1];
		if(a[i]<=0) {Maxsa=i-1; break;}
	}
}
ll sl(int x,ll y){
//	cout<<x<<' '<<y<<'\n';
	if(x>=54){
		if(y<=34) return str2[y];
		return sl(x-1,y-34);
	}
	if(x==0) {if(y<=a1) return str[y]; else return '.';}
	if(y<=34) return str2[y];
	else{
		if(x<=Maxsa&&y>a[x]) return '.';
		if(y<=34) return str2[y];
		else if(y<=a[x-1]+34) {return sl(x-1,y-34);}
		else if(y<=34+a[x-1]+32) {return str2[y-a[x-1]];}
		else if(y<=34+a[x-1]+32+a[x-1]) {return sl(x-1,y-34-a[x-1]-32);}
		else if(y<=a[x-1]+a[x-1]+34+32+2) {return str2[y-a[x-1]-a[x-1]];}
		else {return '.';}
	}
}
int main(){
	a1=strlen(str)-1;
	a2=strlen(str2)-1;
	qw(q);
	clac();
//	printf("%d %d\n",a1,a2);
//	printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
//	printf("%d\n",Maxsa);
//	F(i,1,Maxsa) printf("%I64d ",a[i]);
	while(q--){
		qw(n);
		scanf("%I64d",&k);
		printf("%c",sl(n,k));
	}
	return 0;
}