#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    if(n>26)return 0*printf("-1");
    int vis=0;
    for(int i=0;s[i];i++)
        vis|=1<<(s[i]-'a');
    int cnt=0;
    for(int i=0;i<26;i++)
        cnt+=vis>>i&1;
    return 0*printf("%d",n-cnt);
}