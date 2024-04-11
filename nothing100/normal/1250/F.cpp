#include<bits/stdc++.h>
using namespace std;
int cas,n,f[26];
char ch[550];
int main(){
	scanf("%d",&cas);
	while (cas--){
		memset(f,0,sizeof(f));
		scanf("%s",ch);
		n=strlen(ch);
		for (int i=0;i<n;){
			int j;
			for (j=i;j<n&&ch[j]==ch[i];j++);
			f[ch[i]-'a']|=((j-i)&1);
			i=j;
		}
		for (int i=0;i<26;i++)
		if (f[i]) printf("%c",'a'+i);
		printf("\n");
	}
}