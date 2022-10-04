#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
// from_luogu
int n,m;
int M[3005][3005];
char str[6000];

bool ck(int x,int y){
	if(x<=0||y<=0||x>=n||y>=m) return 0;
	return M[x-1][y-1]&&M[x-1][y]&&M[x-1][y+1]&&M[x+1][y-1]&&M[x+1][y]&&M[x+1][y+1]&&M[x][y-1]&&M[x][y+1];
}

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n){
		scanf("%s",str+1);
		F(j,1,m) if(str[j]=='#') M[i][j]=1;
	}
	F(i,1,n) F(j,1,m){
		if(M[i][j]){
			if(ck(i+1,j)||ck(i+1,j+1)||ck(i+1,j-1)||ck(i,j+1)||ck(i,j-1)||ck(i-1,j+1)||ck(i-1,j)||ck(i-1,j-1));
			else return puts("NO"),0;
		}
	} puts("YES");
	return 0;
}