#include<stdio.h>
char in[10000];
int main(){
    gets(in);
    int i,c;
    for(i=0;in[i];i++){
    if(in[i]>='a'&&in[i]<='z')c=in[i];
    else if(in[i]>='A'&&in[i]<='Z')c=in[i]-'A'+'a';
    }
    puts(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'?"YES":"NO");
}