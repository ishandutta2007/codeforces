#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char S[51][51];
int main(){
	int a=gi(),b=gi(),c=gi(),d=gi(),x,y;
	for(int i=1;i<=50;++i)
		for(int j=1;j<=50;++j)
			if(i<=25)
				if(j<=25)S[i][j]='A';
				else S[i][j]='B';
			else if(j<=25)S[i][j]='C';
			else S[i][j]='D';
	x=1,y=1;
	while(--d){
		S[x][y]='D',y+=2;
		if(y>25)x+=2,y=1;
	}
	x=1,y=26;
	while(--c){
		S[x][y]='C',y+=2;
		if(y>50)x+=2,y=26;
	}
	x=26,y=1;
	while(--b){
		S[x][y]='B',y+=2;
		if(y>25)x+=2,y=1;
	}
	x=26,y=26;
	while(--a){
		S[x][y]='A',y+=2;
		if(y>50)x+=2,y=26;
	}
	printf("50 50\n");
	for(int i=1;i<=50;++i)printf("%s\n",S[i]+1);
	return 0;
}