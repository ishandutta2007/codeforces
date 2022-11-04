#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int num[10];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        cin>>s;
        for(int i=0;i<7;i++)
            if(s[i]=='1') num[i]++;
    }
    int ans=0;
    for(int i=0;i<7;i++)
        ans=max(ans,num[i]);
    printf("%d\n",ans);
    return 0;
}