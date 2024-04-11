#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define LL long long
#define M
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
int n,x,y,h;
void opt(int X,int Y){putchar(' '),putchar(X-1+'a'),putchar(Y+'0');}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),n--,x=1,h=1,printf("a1");
	while(n>16){
		n-=16;
		for(int i=2;i<=8;i++) opt(i,h);
		h++;
		for(int i=8;i>=1;i--) opt(i,h);
		h++,opt(x,h);
	}
	for(int i=1;i<=2&&n>4;i++){
		h++,opt(x,h),x++,opt(x,h);
		h--,opt(x,h),x++,opt(x,h),n-=4;
	}
	if(h<7){
		if(n>4){
			h++,opt(x,h),x++,opt(x,h);
			h--,opt(x,h),x++,opt(x,h),n-=4;
		}
		h=8,opt(x,h),n--;
		for(int i=1;n>0;i++) if(i!=x) n--,opt(i,h);
	}
	else{
		if(n==1) opt(8,h);
		else if(n==2) opt(x,8),opt(x+1,8);
		else{
			int last;
			for(int i=8;n>1&&i>x;i--) n--,opt(i,h),last=i;
			n--,opt(last,8);
			for(int i=x;n>0;i++) if(i!=last) opt(i,8),n--;
		}
	}
	opt(8,8),puts("");
	return 0;
}