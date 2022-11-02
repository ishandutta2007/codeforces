#include<bits/stdc++.h>
using namespace std;
int cas,l,s[2],a[2][300030],tail[2];
char ch[300030];
int main(){
	scanf("%d",&cas);
	while (cas--){
		scanf("%s",ch);
		l=strlen(ch);
		s[0]=s[1]=0;
		for (int i=0;i<l;i++){
			int tmp=ch[i]-'0';
			a[tmp&1][s[tmp&1]++]=tmp;
		}
		tail[0]=tail[1]=0;
		for (int i=0;i<l;i++){
			if (tail[0]==s[0]) printf("%d",a[1][tail[1]++]);
			else if (tail[1]==s[1]) printf("%d",a[0][tail[0]++]);
			else{
				if (a[0][tail[0]]<a[1][tail[1]]) printf("%d",a[0][tail[0]++]);
				else printf("%d",a[1][tail[1]++]);
			}
		}
		printf("\n");
	}
}