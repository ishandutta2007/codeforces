#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const char cf[]="CODEFORCES";
char s[105];
int main()
{
    scanf("%s",&s);
    int t=strlen(cf);
    int n=strlen(s);
    if(n<t)
    {
        printf("NO\n");
        return 0;
    }
    int loc1=0,loc2=t-1;
    for(int i=0;i<n;i++)
    {
        if(loc1<t && s[i]==cf[loc1])
        {
            loc1++;
        }
        else
        {
            break;
        }
    }
    if(loc1==10)
    {
        printf("YES\n");
        return 0;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(loc2>=0 && s[i]==cf[loc2])
        {
            loc2--;
            loc1++;
            if(loc1==10)break;
        }
        else
        {
            break;
        }
    }
    //printf("%d\n",loc1);
    if(loc1==t)printf("YES\n");
    else printf("NO\n");
    return 0;
}