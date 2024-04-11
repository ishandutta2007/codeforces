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
int n,Ans;
bool use[100],use2[100],gues=0;
char str1[100],str2[100000];
int main(){
	qw(n);
	F(i,0,25) use[i]=1;
	F(i,1,n){
		scanf("%s%s",str1,str2);
		int len=strlen(str2);
		F(j,0,25) use2[j]=0;
		F2(j,0,len) use2[str2[j]-'a']=1;
		if(str1[0]=='!'){
			F(j,0,25) if(!use2[j]) use[j]=0;
			if(gues) ++Ans;
		}
		if(str1[0]=='.'){
			F(j,0,25) if(use2[j]) use[j]=0;
		}
		if(str1[0]=='?'){
			if(i!=n)
				use[str2[0]-'a']=0;
			if(gues&&i!=n) ++Ans;
		}
		int cnt=0;
		F(j,0,25) if(use[j]) ++cnt;
//		F(j,0,25) printf("%d ",use[j]); puts("");
		if(cnt==1) gues=1;
	}
	printf("%d",Ans);
	return 0;
}