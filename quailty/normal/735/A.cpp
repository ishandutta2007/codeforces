#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
char s[MAXN];
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    int st=0,ed=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G')st=i;
        if(s[i]=='T')ed=i;
    }
    if(st>ed)swap(st,ed);
    if((st-ed)%k)return 0*printf("NO");
    for(int i=st;i<=ed;i+=k)
        if(s[i]=='#')return 0*printf("NO");
    return 0*printf("YES");
}