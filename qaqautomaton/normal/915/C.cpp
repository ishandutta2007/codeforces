#include<bits/stdc++.h>
using namespace std;
char a[30],b[30];
int c[18];

int ext(int x,int len){
    --c[b[x]-'0'];
    int it=x+1;
    for(int i=0;i<=9;++i){
        for(int j=0;j<c[i];++j)if(i<b[it]-'0'){++c[b[x]-'0'];return 1;}
        else if(i>b[it]-'0'){++c[b[x]-'0'];return 0;}
        else ++it;
    }
    ++c[b[x]-'0'];
    return 1;
}
int main(){
    scanf("%s%s",a,b);
    for(char *ch=a;*ch;++ch)++c[*ch-'0'];
    if(strlen(a)<strlen(b)){
        for(int i=9;~i;--i)while(c[i]){--c[i];putchar(i+'0');}
        putchar('\n');
        return 0;
    }
    int lenb=strlen(b);
    for(int i=0;i<lenb;++i){
        if((!c[b[i]-'0'])||(!ext(i,lenb))){
            int j;
            for(j=b[i]-'0'-1;!c[j];--j);
            --c[j];
            putchar(j+'0');
            for(j=9;~j;--j){
                while(c[j]){--c[j];putchar(j+'0');}
            }
            putchar('\n');
            return 0;
        }
        else{
            --c[b[i]-'0'];
            putchar(b[i]);
        }
    }
    putchar('\n');
	return 0;
}