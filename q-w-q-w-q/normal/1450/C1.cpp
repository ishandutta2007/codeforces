#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n;
char a[301][301];
int s[3][2],ans[3];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			for(int j=1;j<=n;j++){
				if(a[i][j]=='O') s[(i+j)%3][0]++;
				if(a[i][j]=='X') s[(i+j)%3][1]++;
			}
		}
		int x=max(s[0][0]+s[0][1],max(s[1][0]+s[1][1],s[2][0]+s[2][1])),t1,t2;
		if(s[0][0]+s[0][1]==x) t1=1,t2=2;
		else if(s[1][0]+s[1][1]==x) t1=0,t2=2;
		else t1=0,t2=1;
		if(s[t1][0]+s[t2][1]<s[t1][1]+s[t2][0]) ans[t1]=1,ans[t2]=-1;
		else ans[t1]=-1,ans[t2]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ans[(i+j)%3]==0||a[i][j]=='.') putchar(a[i][j]);
				else if(ans[(i+j)%3]==1) putchar('X');
				else putchar('O');
			}
			putchar('\n');
		}
	}
}