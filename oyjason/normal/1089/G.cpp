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
int n,a[80],sum,last,m,p[50],k;
int calc(int st){
	if(m-st+1>=k) return p[st+k-1]-p[st]+1;
	int rem=k-(m-st+1),now=7-p[st]+1;
	if(rem%m>0) return now+(rem/m)*7+p[rem%m];
	return now+((rem/m)-1)*7+p[m];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int T=read();T;T--){
		m=0,k=read(); int ans=2000000000;
		for(int i=1;i<=7;i++){
			a[i]=read(),sum+=a[i];
			if(a[i]) p[++m]=i;
		}
		for(int i=1;i<=m;i++) ans=min(ans,calc(i));
		printf("%d\n",ans);
	}
	return 0;
}