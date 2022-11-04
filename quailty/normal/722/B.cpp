#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int p[105];
char s[105];
bool isVovel(char x)
{
    return x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='y';
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    gets(s);
    for(int i=1;i<=n;i++)
    {
        gets(s);
        for(int j=0;s[j];j++)
            p[i]-=isVovel(s[j]);
        if(p[i])return 0*printf("NO");
    }
    return 0*printf("YES");
}