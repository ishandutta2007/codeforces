#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool isVowel(char x)
{
    return x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='Y';
}
int main()
{
    char s[105];
    scanf("%s",s);
    int n=strlen(s),la=-1,res=0;
    for(int i=0;i<n;i++)
        if(isVowel(s[i]))
        {
            res=max(res,i-la);
            la=i;
        }
    res=max(res,n-la);
    return 0*printf("%d",res);
}