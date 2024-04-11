#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dir[4][2]={0,1,1,0,0,-1,-1,0},maxn=50;
int mp[4],n,m,stx,sty,edx,edy,ans;
bool b[maxn+10][maxn+10];
char s[maxn*2+10]; int l;
bool work(){
	int x=stx,y=sty;
	for(int i=0;i<l;++i){
		x+=dir[mp[s[i]-'0']][0];
		y+=dir[mp[s[i]-'0']][1];
		if(x<=0||x>n||y<=0||y>m||b[x][y]) return 0;
		if(x==edx&&y==edy) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			char c=getchar(); for(;!isgraph(c);c=getchar());
			if(c=='#') b[i][j]=1;
			else if(c=='S') stx=i,sty=j;
			else if(c=='E') edx=i,edy=j;
		}
	scanf("%s",s); l=strlen(s);
	for(int i=0;i<4;++i) mp[i]=i;
	for(int i=1;i<=24;++i){
		ans+=work(); next_permutation(mp,mp+4);
	}
	printf("%d",ans);
}