#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
char A[MAXN],B[MAXN];
int cmp(char x[],char y[],int len)
{
    for(int i=0;i<len;i++)
        if(x[i]<y[i])return -1;
        else if(x[i]>y[i])return 1;
    return 0;
}
void work(char x[],int len)
{
    if(len&1)return;
    work(x,len/2);
    work(x+len/2,len/2);
    if(cmp(x,x+len/2,len/2)>0)
        for(int i=0;i<len/2;i++)
            swap(x[i],x[i+len/2]);
}
int main()
{
    scanf("%s%s",A,B);
    int len=strlen(A);
    work(A,len);
    work(B,len);
    printf("%s\n",strcmp(A,B)==0 ? "YES" : "NO");
    return 0;
}