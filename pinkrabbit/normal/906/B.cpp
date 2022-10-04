#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
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
int nn,mm,n,m;
vector<int> a[100001];
vector<int> b[100001];
const int zh4[2][5]={0,2,4,1,3,0,3,1,4,2};
const int zh5[2][6]={0,1,3,5,2,4,0,2,4,1,3,5};
const int zh6[2][7]={0,1,3,5,2,4,6,0,2,4,6,1,3,5};
const int zh7[2][8]={0,1,3,5,7,2,4,6,0,2,4,6,1,3,5,7};
void print1(){
	F(i,1,n){
		F(j,1,m)
			printf("%d ",b[i][j]);
		puts("");
	}
}
void print2(){
	F(j,1,m){
		F(i,1,n)
			printf("%d ",b[i][j]);
		puts("");
	}
}
int main(){
	qw(nn,mm);
	if(nn==1&&mm==1) {puts("YES\n1"); return 0;}
	if(nn==3&&mm==3) {puts("YES\n7 6 2\n1 8 4\n5 3 9"); return 0;}
	if(max(nn,mm)<4){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(nn<=mm) n=nn, m=mm;
	else n=mm, m=nn;
	if(nn<=mm){
		F(i,1,n){
			a[i].push_back(0);
			b[i].push_back(0);
			F(j,1,m)
				a[i].push_back((i-1)*m+j),
				b[i].push_back(0);
		}
	}
	else{
		F(i,1,n)
			a[i].push_back(0),
			b[i].push_back(0);
		F(j,1,m){
			F(i,1,n)
				a[i].push_back((j-1)*n+i),
				b[i].push_back(0);
		}
	}
	int x=(m-4)/4, y=m%4;
	if(y==0) ++x;
	F(i,1,n){
		F(j,1,x){
			b[i][j*4-3]=a[i][j*4+zh4[i&1][1]-4];
			b[i][j*4-2]=a[i][j*4+zh4[i&1][2]-4];
			b[i][j*4-1]=a[i][j*4+zh4[i&1][3]-4];
			b[i][j*4]=a[i][j*4+zh4[i&1][4]-4];
		}
	}
//	F(i,1,n){
//		F(j,1,x){
//			printf("%d %d %d %d ",b[i][j*4-3],b[i][j*4-2],b[i][j*4-1],b[i][j*4]);
//		} puts("");
//	}
	if(y==0){
		if(nn<=mm) print1();
		else print2();
		return 0;
	}
	if(y==1){
		int l=m-5;
		F(i,1,n){
			b[i][l+1]=a[i][l+zh5[i&1][1]];
			b[i][l+2]=a[i][l+zh5[i&1][2]];
			b[i][l+3]=a[i][l+zh5[i&1][3]];
			b[i][l+4]=a[i][l+zh5[i&1][4]];
			b[i][l+5]=a[i][l+zh5[i&1][5]];
		}
	}
	if(y==2){
		int l=m-6;
		F(i,1,n){
			b[i][l+1]=a[i][l+zh6[i&1][1]];
			b[i][l+2]=a[i][l+zh6[i&1][2]];
			b[i][l+3]=a[i][l+zh6[i&1][3]];
			b[i][l+4]=a[i][l+zh6[i&1][4]];
			b[i][l+5]=a[i][l+zh6[i&1][5]];
			b[i][l+6]=a[i][l+zh6[i&1][6]];
		}
	}
	if(y==3){
		int l=m-7;
		F(i,1,n){
			b[i][l+1]=a[i][l+zh7[i&1][1]];
			b[i][l+2]=a[i][l+zh7[i&1][2]];
			b[i][l+3]=a[i][l+zh7[i&1][3]];
			b[i][l+4]=a[i][l+zh7[i&1][4]];
			b[i][l+5]=a[i][l+zh7[i&1][5]];
			b[i][l+6]=a[i][l+zh7[i&1][6]];
			b[i][l+7]=a[i][l+zh7[i&1][7]];
		}
	}
	if(nn<=mm) print1();
	else print2();
	return 0;
}