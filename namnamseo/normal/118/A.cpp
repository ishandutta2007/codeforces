#include <cstdio>

int main()
{
    char buf[150];
    bool vowel[26];
    int i;
    for(i=0;i<26;i++) vowel[i]=false;
    vowel['A'-'A']=true;
    vowel['O'-'A']=true;
    vowel['Y'-'A']=true;
    vowel['E'-'A']=true;
    vowel['U'-'A']=true;
    vowel['I'-'A']=true;
    scanf("%s",buf);
    for(int i=0;buf[i];i++){
        if(buf[i]>='a'){
            if(vowel[buf[i]-'a']) continue;
        } else if(vowel[buf[i]-'A']) continue;
        putchar('.');
        if(buf[i]<='Z') buf[i]+='a'-'A';
        putchar(buf[i]);
    }
    return 0;
}