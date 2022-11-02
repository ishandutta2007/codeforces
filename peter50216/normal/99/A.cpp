#include<stdio.h>
#include<string.h>
char in[10000],in2[10000];
int main(){
    scanf("%[^.].%s",in,in2);
    if(in[strlen(in)-1]=='9'){
    puts("GOTO Vasilisa.");
    return 0;
    }
    if(in2[0]>='5'){
    in[strlen(in)-1]++;
    }
    puts(in);
}