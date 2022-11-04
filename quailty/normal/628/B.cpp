#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[300005];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    ll res=0;
    for(int i=0;i<n;i++)
        res+=((s[i]-'0')%4==0);
    for(int i=1;i<n;i++)
    {
        int t=(s[i-1]-'0')*10+(s[i]-'0');
        if(t%4==0)res+=i;
    }
    printf("%I64d",res);
    return 0;
}