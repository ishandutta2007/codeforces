#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int N=105;
int T,n;
char s[5];
bool ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='<';
}
int sta[2][N],top[2];
int main()
{
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		top[0]=top[1]=0;
		rep(i,(n+1)/2)sta[0][++top[0]]=i;
		for(int i=(n+1)/2+1;i<=n+1;++i)
			sta[1][++top[1]]=i;
		rep(i,n){
			for(int typ=0;typ<2;++typ)
				rep(i,top[typ]-1)if(ask(sta[typ][i],sta[typ][i+1]))
					swap(sta[typ][i],sta[typ][i+1]);
			int mi=1;
			if(ask(sta[0][top[0]],sta[1][top[1]]))mi=0;
			--top[mi];
			if(i!=n){
				int inn=n+i+1;
				sta[mi][++top[mi]]=inn;
			}
		}
		puts("!");
		fflush(stdout);
	}	
	return 0;
}