#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{
    int n,a,b;
    scanf("%d%d%d%s",&n,&a,&b,s);
    printf("%d\n",(s[a-1]==s[b-1])^1);
    return 0;
}