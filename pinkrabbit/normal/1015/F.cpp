#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define Mod 1000000007
int n,m;
char s[205];
int p[205];
int f[205][105][205];
void P(int&x,int y){x-=(x+=y)>=Mod?Mod:0;}
int main(){
	scanf("%d%s",&n,s+1);
	m=strlen(s+1);
	p[1]=0;
	F(i,2,m){
		int k=p[i-1];
		while(k&&s[k+1]!=s[i]) k=p[k];
		if(s[k+1]==s[i]) p[i]=k+1;
	}
	f[0][0][0]=1;
	F2(i,0,n+n){
		F(j,(i+1)/2,min(i,n)){
			F(k,0,min(i,m)){
				// f[i][j][k]
				int now=f[i][j][k];
				if(!now) continue;
				if(k==m){
					if(j+j>=i+1) P(f[i+1][j][m],now);
					P(f[i+1][j+1][m],now);
					continue;
				}
				int x=k;
				while(x&&s[x+1]!='(') x=p[x];
				if(s[x+1]=='(') ++x;
				P(f[i+1][j+1][x],now);
				
				if(j+j==i) continue;
				
				x=k;
				while(x&&s[x+1]!=')') x=p[x];
				if(s[x+1]==')') ++x;
				P(f[i+1][j][x],now);
			}
		}
	}
	printf("%d\n",f[n+n][n][m]);
	return 0;
}