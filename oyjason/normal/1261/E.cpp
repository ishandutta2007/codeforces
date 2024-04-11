#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rint register int 
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 1020
int n,m;
int pos[M],A[M];
int dif[M],tk[M];
char ch[M][M];
inline bool cmp(int a,int b){return A[a]>A[b];}
inline void solve(int _pos,int cnt){
	memset(tk,0,sizeof(tk));
	for(int i=m;i>0&&cnt>0;i--) if(dif[i+1]==2&&dif[i]==0)
		dif[i]=1,tk[i]=1,--cnt;
	for(int i=m;i>0&&cnt>0;i--) if(tk[i]==0&&(dif[i]!=2||dif[i+1]!=1)){
		tk[i]=1,--cnt;
		if(dif[i]!=2) dif[i]=1;
		if(dif[i+1]==1) dif[i+1]=0;
	}
	for(int i=m;i>0&&cnt>0;i--) if(tk[i]==0) tk[i]=1,--cnt;
	for(int i=m;i>1;i--) if(dif[i]<2&&tk[i]!=tk[i-1]) dif[i]=2;
	for(int i=1;i<=m;i++) ch[i][_pos]=tk[i]+'0';
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) A[i]=read(),pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	m=A[pos[1]]+1;
	if(m==2){
		printf("%d\n",n);
		for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++) putchar((i==j)+'0');
		return 0;
	}
	dif[m]=dif[1]=dif[m+1]=2;
	for(int i=1;i<m;i++) ch[i][pos[1]]='1'; ch[m][pos[1]]='0';
//	if(A[pos[2]]<=1) --m;
	for(int i=2;i<=n;i++) solve(pos[i],A[pos[i]]);
	printf("%d\n",m);
	for(int i=1;i<=m;i++,putchar('\n')) for(int j=1;j<=n;j++) putchar(ch[i][j]);
	return 0;
}