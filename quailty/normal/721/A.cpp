#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
vector<int>res;
int main()
{
    int n;
    scanf("%d%s",&n,s);
    int now=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')now++;
        else
        {
            if(now)res.push_back(now);
            now=0;
        }
    }
    if(now)res.push_back(now);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}