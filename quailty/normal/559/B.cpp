#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
char A[MAXN],B[MAXN];
bool cmp(char x[],char y[],int len)
{
    bool isok=1;
    for(int i=0;i<len;i++)
        if(x[i]!=y[i])isok=0;
    return isok;
}
bool equ(char x[],char y[],int len)
{
    if(cmp(x,y,len))return 1;
    if(len%2==0)
        if(equ(x,y+len/2,len/2))
            return equ(x+len/2,y,len/2);
        else
            return equ(x+len/2,y+len/2,len/2)&&equ(x,y,len/2);
    return 0;
}
int main()
{
    scanf("%s%s",A,B);
    int len=strlen(A);
    printf("%s\n",equ(A,B,len) ? "YES" : "NO");
    return 0;
}