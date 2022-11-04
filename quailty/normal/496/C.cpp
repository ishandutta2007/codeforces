#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
string s[105];
char c[105][105];
bool judge(int k)
{
    for(int i=0;i<n-1;i++)
        if(s[i]+c[i][k]>s[i+1]+c[i+1][k])return 0;
    for(int i=0;i<n;i++)
        s[i]+=c[i][k];
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    int cnt=0;
    for(int i=0;i<m;i++)cnt+=judge(i);
    printf("%d\n",m-cnt);
    return 0;
}