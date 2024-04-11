#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const char t[]="bear";
char s[5005];
int main()
{
    scanf("%s",s);
    int n=strlen(s),res=0;
    for(int i=0;i<n;i++)
    {
        int k=0;
        for(int j=i;j<n;j++)
        {
            if(k<4)k=(s[j]==t[k] ? k+1 : s[j]==t[0]);
            if(k==4)res++;
        }
    }
    return 0*printf("%d",res);
}