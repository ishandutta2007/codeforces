#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char n[15];
    int k;
    scanf("%s%d",n,&k);
    int len=strlen(n),cnt=0,res=0;
    for(int i=len-1;i>=0 && cnt<k;i--)
    {
        if(n[i]=='0')cnt++;
        else res++;
    }
    return 0*printf("%d",(cnt>=k ? res : len-1));
}