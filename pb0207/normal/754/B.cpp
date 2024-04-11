#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[10][10];

char ss[10];

int flag=0;
void dfs(){
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
			  if(s[i][j]=='x'&&s[i+1][j]=='x'&&s[i+2][j]=='x'){
			  	flag=1;
			  	return;
			  }
			  if(s[i][j]=='x'&&s[i][j+1]=='x'&&s[i][j+2]=='x'){
			  	flag=2;
			  	return;
			  }
			  if(s[i][j]=='x'&&s[i+1][j+1]=='x'&&s[i+2][j+2]=='x'){
			  	flag=3;
			  	return;
			  }
			  if(s[i][j]=='x'&&s[i-1][j-1]=='x'&&s[i-2][j-2]=='x'){
			  	flag=3;
			  	return;
			  }
			  if(s[i][j]=='x'&&s[i-1][j+1]=='x'&&s[i-2][j+2]=='x'){
			  	flag=3;
			  	return;
			  }
			  if(s[i][j]=='x'&&s[i+1][j-1]=='x'&&s[i+2][j-2]=='x'){
			  	flag=3;
			  	return;
			  }
			}
		}
		return ;
}
int main(){
	int n,x,m=0;
	memset(s,0,sizeof(s));
	for(int i=1;i<=4;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			m=0;
			if(s[i][j]=='.'&&flag==0){
				s[i][j]='x';
				dfs();
				m=1;
			}
			if(m==1)
			  s[i][j]='.';
		
		}
		if(flag==1)
		break;
	}
	if(flag>=1)
      printf("YES\n",flag);
	else printf("NO\n");
    return 0;
}