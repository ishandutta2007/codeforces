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
int n,p[100000],m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=2;i*i<=n;i++) if(n%i==0){
		p[++m]=i; if(i*i<n) p[++m]=n/i;
	}
	if(m<=1){puts("NO");return 0;}
	sort(p+1,p+m+1);
	int t1=p[1],t2;
	for(int i=2;i<=m;i++){
		if(p[i]%t1!=0){t2=p[i];break;}
		if(i==m){puts("NO");return 0;} 
	}
	swap(t1,t2);
	for(int i=0;i*t1<=n;i++){
		if(t1*i%t2==(n-1)%t2){
			puts("YES");
			puts("2");
			printf("%d %d\n",i,n/t1);
			printf("%d %d\n",(n-1-(t1*i))/t2,n/t2);
			return 0;
		}
	}
	puts("NO");
	return 0;
}