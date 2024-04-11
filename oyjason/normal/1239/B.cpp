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
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
#define M 1200020
int n,m,top,match[M],S[M],pre[M],st=1;
int q[M],ans0,ans1,ans2,a1,b1,a2,b2;
char ch[M];
int main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++) pre[i+n]=pre[i]=(pre[i-1]+((ch[i]=='(')?1:(-1))),ch[i+n]=ch[i];
//	for(int i=1;i<=n;i++) debug(i)sp,debug(pre[i])sp,putchar(ch[i]),puts("");
//	debug(pre[n])el;
	if(pre[n]!=0){puts("0\n1 1");return 0;}
	for(int i=0;i<n;i++) if(pre[i]<pre[st-1]&&ch[i+1]=='(') st=i+1;
	if(st>n) st-=n;
	for(int i=st;i<st+n;i++){
		if(ch[i]=='(') S[++top]=i;
		else match[i]=S[top],match[S[top]]=i,top--;
	}
//	for(int i=st;i<st+n;i++) if(ch[i]=='(') solve(i);
	for(int x=st;x<st+n;x=match[x]+1,ans0++);
	if((ans0<<1)==n){printf("%d\n1 1",ans0);return 0;}
	for(int x=st;x<st+n;x=match[x]+1){
		int tt=1,y=x+1;
		while(y<match[x]){
			tt++;
			int z=y+1,ttt=ans0+1;
			while(z<match[y]) z=match[z]+1,ttt++;
			if(ttt>ans2) ans2=ttt,a2=y,b2=match[y];
			y=match[y]+1;
		}		
		if(ans2<tt) ans2=tt,a2=x,b2=match[x];
	}
	if(a2>n) a2-=n; if(b2>n) b2-=n;
	printf("%d\n%d %d\n",ans2,a2,b2);
	return 0;
}