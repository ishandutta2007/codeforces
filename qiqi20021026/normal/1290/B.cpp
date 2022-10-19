#include<bits/stdc++.h>

using namespace std;

#define N 300000

int read();

int n,m,s[N][26]; char ch[N];
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	for (int i=1; i<=n; i++)
		for (int j=0; j<26; j++) s[i][j]=s[i-1][j]+(ch[i]=='a'+j);
	scanf("%d",&m);
	for (int i=1; i<=m; i++){
		int x,y; scanf("%d%d",&x,&y);
		if (x==y){ puts("Yes"); continue; }
		int tmp=0;
		for (int j=0; j<26; j++) tmp+=(s[x-1][j]<s[y][j]);	
		if (tmp==1){ puts("No"); continue; }
		if (tmp==2) puts(ch[x]==ch[y]?"No":"Yes"); else puts("Yes");
	}
	return 0;
}

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}