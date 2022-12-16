#include <stdio.h>
#include <algorithm>
#define MN 1000

int n,m;
char c[MN+5][MN+5];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&c[i][1]);
	if(m&1){
		puts("YES");
		for(int i=1;i<=m+1;i++)
			printf("%d%c",(i&1)?1:2," \n"[i==m+1]);
		return;
	}
	if(c[1][2]==c[2][1]){
		puts("YES");
		for(int i=1;i<=m+1;i++)
			printf("%d%c",(i&1)?1:2," \n"[i==m+1]);
		return;
	}
	if(n==2){
		puts("NO");
		return;
	}
	if(c[1][3]==c[3][1]){
		puts("YES");
		for(int i=1;i<=m+1;i++)
			printf("%d%c",(i&1)?1:3," \n"[i==m+1]);
		return;
	}
	if(c[2][3]==c[3][2]){
		puts("YES");
		for(int i=1;i<=m+1;i++)
			printf("%d%c",(i&1)?2:3," \n"[i==m+1]);
		return;
	}
	if(c[1][2]==c[2][3]&&c[2][3]==c[3][1]){
		puts("YES");
		for(int i=1;i<=m+1;i++)
			printf("%d%c",(i-1)%3+1," \n"[i==m+1]);
		return;
	}
	int p[3] = {1,2,3};
	if(c[2][1]==c[2][3])
		std::swap(p[0],p[1]);
	if(c[3][1]==c[3][2])
		std::swap(p[0],p[2]);
	if(c[p[0]][p[1]]==c[p[1]][p[2]])
		std::swap(p[1],p[2]);
	int t = m/2;
	if(t==1){
		puts("YES");
		printf("%d %d %d\n",p[1],p[2],p[0]);
		return;
	}
	if(t&1){
		t -= 3;
		t /= 2;
		puts("YES");
		for(int i=0;i<t;i++){
			printf("%d %d ",p[1],p[0]);
		}
		printf("%d %d %d %d %d %d %d",p[1],p[0],p[1],p[2],p[0],p[1],p[0]);
		for(int i=0;i<t;i++){
			printf(" %d %d",p[1],p[0]);
		}
		puts("");
		return;
	}else{
		puts("YES");
		for(int i=4;i<=m;i+=4)
			printf("%d %d %d %d ",p[2],p[0],p[2],p[1]);
		printf("%d\n",p[2]);
		return;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}