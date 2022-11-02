#include<stdio.h>
#include<string>
using namespace std;
char in[10000];
string gn(){
    scanf("%s",in);
    for(int i=0;in[i];i++)if(in[i]>='A'&&in[i]<='Z')in[i]=in[i]-'A'+'a';
    return in;
}
int main(){
    string a,b;
    a=gn();b=gn();
    if(a<b)puts("-1");
    else if(a>b)puts("1");
    else puts("0");
}