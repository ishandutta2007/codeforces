#include<stdio.h>
#include<string.h>
char in[110];
int main(){
    scanf("%s",in);
    int i;
    for(i=0;in[i];i++){
	int c=in[i];
	if(c>='A'&&c<='Z')c=c-'A'+'a';
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y');
	else printf(".%c",c);
    }
}