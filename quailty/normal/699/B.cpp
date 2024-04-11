#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
char s[MAXN][MAXN];
int cnty[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cnty[j]+=(s[i][j]=='*');
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cnty[j]-=(s[i][j]=='*');
        int cnt=0;
        for(int j=0;j<m;j++)
            cnt+=(cnty[j]>0);
        if(cnt<=1)
        {
            int loc=0;
            for(int j=0;j<m;j++)
                if(cnty[j]>0)loc=j;
            return 0*printf("YES\n%d %d",i+1,loc+1);
        }
        for(int j=0;j<m;j++)
            cnty[j]+=(s[i][j]=='*');
    }
    return 0*printf("NO");
}