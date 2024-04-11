#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define uint unsigned int
#define ULL unsigned long long
#define LDB long double 
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(LL x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline LL read(){
		LL nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 200200
int p[M],m,l[M],r[M],k,n;
char ch[M];
inline void solve(){
	n=read(),k=read(),m=0;
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++) p[i]=((ch[i]=='(')?1:-1);
	int st=1;
	while(k>1){
		--k;
		if(p[st]!=1){	
			int rs=st+1;
			while(p[rs]!=1) ++rs;
			reverse(p+st,p+rs+1);
			++m,l[m]=st,r[m]=rs;
		} ++st;
		if(p[st]==1){
			int rs=st+1;
			while(p[rs]!=-1) ++rs;
			reverse(p+st,p+rs+1);
			++m,l[m]=st,r[m]=rs;
		} ++st;
	}
	for(;st<=n;++st) if(p[st]==-1){
		int rs=st+1;
		while(rs<=n&&p[rs]!=1) ++rs;
		if(rs>n) break;
		reverse(p+st,p+rs+1);
		++m,l[m]=st,r[m]=rs;
	} printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d %d\n",l[i],r[i]);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}