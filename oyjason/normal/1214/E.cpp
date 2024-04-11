#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define pii pair<int,int>
#define ULL unsigned long long

#define LL long long
using namespace std;
namespace IO{
	const int BS=(1<<20)+5; int Top=0;
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
} using namespace IO;
#define M 400200
int u[M],v[M],m,n,d[M],id[M],cnt,dep[M],S[M],top=0,pos;
inline bool cmp(int x,int y){return d[x]<d[y];}
inline void add(int x,int y){printf("%d %d\n",x,y);}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) id[i]=i,d[i]=read()-1;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<n;i++) add(id[i]*2,id[i+1]*2);
	for(int i=n;i>0;i--){
		if(pos>i) pos=i,top=0; 
		if(i-d[id[i]]>0){
			pos=i-d[id[i]],S[top=1]=id[i],add(id[pos]*2,id[i]*2-1);continue;
		}
		while(i-pos+top>d[id[i]]) --top;
		assert(i-pos+top==d[id[i]]);
		add(S[top]*2-1,id[i]*2-1);
		S[++top]=id[i];
	}
	return 0;
}