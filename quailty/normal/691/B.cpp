#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const char ok[]="AbdHIMOopqTUVvWwXxY";
const char mr[]="AdbHIMOoqpTUVvWwXxY";
char s[1005],t[1005];
int main()
{
    int tot=strlen(ok);
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        bool isok=0;
        for(int j=0;j<tot;j++)
            if(s[i]==ok[j])
            {
                t[n-1-i]=mr[j];
                isok=1;
            }
        if(!isok)return 0*printf("NIE");
    }
    printf("%s",(strcmp(s,t)==0 ? "TAK" : "NIE"));
    return 0;
}