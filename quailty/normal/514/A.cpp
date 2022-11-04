#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char num[20];
    scanf("%s",num);
    int n=strlen(num);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(num[i]>'4'&&num[i]!='9')num[i]=9+2*'0'-num[i];
        }
        else
        {
            if(num[i]>'4')num[i]=9+2*'0'-num[i];
        }
    }
    printf("%s",num);
    return 0;
}