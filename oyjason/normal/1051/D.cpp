#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 2020
#define mod 998244353
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,F[M>>1][M][4],ans;
int add(int x,int y){return (x+y)>=mod?x+y-mod:x+y;}
int upd(int &x,int y){x=add(x,y);} 
int main(){
	n=read(),m=read();
	F[1][2][1]=F[1][2][2]=F[1][1][0]=F[1][1][3]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=i+i;j++){
			for(int k=0;k<4;k++){
				if(!F[i][j][k]) continue;
				for(int ot=0;ot<4;ot++){
					LL dt=0;
					if((k^ot)==3) dt=1+(k!=0&&k!=3);
					else if((k^ot)==0) dt=0;
					else dt=(ot>0&&ot<3);
					upd(F[i+1][j+dt][ot],F[i][j][k]);
				}
			}
		}
	}
	for(int i=0;i<4;i++) upd(ans,F[n][m][i]);
	printf("%d\n",ans); return 0;
}