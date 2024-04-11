#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define LL long long
#define pii pair<int,int>
#define T1 first
#define T2 second
#define mp make_pair
#define M 202
using namespace std;
namespace IO{
    const int BS=(1<<23)+5; int Top=0;
    char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
    char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
    void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
    void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
    void write(int x){
        if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
        while(x) SS[++Top]=x%10,x/=10;
        while(Top) Putchar(SS[Top]+'0'),--Top;
    }
    int read(){
        int nm=0,fh=1; char cw=getchar();
        for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
        for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
        return nm*fh;
    }
}using namespace IO;
int F[5][5][300][300],aa[50],bb[50];
int main(){
	//freopen(".in","r",stdin);
	memset(F,-1,sizeof(F)),F[0][0][0][0]=0;
	for(int s1=0;s1<3;s1++) for(int s2=0;s2<3;s2++) if(s1+s2<5){
		for(int j=0;j<M;j++) for(int k=0;k<M;k++) if(F[s1][s2][j][k]!=-1){
			int bas=(s1+s2==4?15:25);
			if(s1<3){
				for(int t2=0;t2+k<M;t2++){
					int t1=max(bas,t2+2); if(t1+j>=M) break;
					assert(j+t1<M),assert(k+t2<M);
					F[s1+1][s2][j+t1][k+t2]=t1*M+t2;
				}
			}
			if(s2<3){
				for(int t1=0;t1+j<M;t1++){
					int t2=max(bas,t1+2); if(t2+k>=M) break;
					assert(j+t1<M),assert(k+t2<M);
					F[s1][s2+1][j+t1][k+t2]=t1*M+t2;
				}
			}
		}
	}
	
/*
	
	for(int s1=0;s1<=3;s1++) for(int s2=0;s2<=3;s2++)
	for(int j=0;j<100;j++) for(int k=0;k<100;k++) if(F[s1][s2][j][k]!=-1)
		printf("s1 = %d   s2 = %d   j = %d   k = %d    %d \n",s1,s2,j,k,F[s1][s2][j][k]);
	return 0;
	
	*/
	for(int T=read();T;T--){
		int A=read(),B=read(),w1=-10,w2=-5,top=A+B,cnt=A+B;
		for(int s1=0;s1<=3;s1++){
			for(int s2=0;s2<=3;s2++){
				if(F[s1][s2][A][B]==-1||max(s1,s2)<3) continue;
				if(s1-s2>w1-w2) w1=s1,w2=s2;
			}
		}
		if(w1<0){puts("Impossible");continue;}
		top=cnt=w1+w2;
		printf("%d:%d\n",w1,w2);
		while(cnt){
			int t1=F[w1][w2][A][B]/M,t2=F[w1][w2][A][B]%M;
//			debug(w1)sp,debug(w2)sp,debug(t1)sp,debug(t2)el,debug(cnt)el;
			aa[cnt]=t1,bb[cnt]=t2,A-=t1,B-=t2,cnt--;
			if(t1>t2) w1--; else w2--; 
		}
		for(int i=1;i<=top;i++) printf("%d:%d%c",aa[i],bb[i],i<top?' ':'\n');
	}
	return 0;
}