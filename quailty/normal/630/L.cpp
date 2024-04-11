#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[10];
int main()
{
    scanf("%s",s);
    swap(s[1],s[2]);
    swap(s[2],s[4]);
    ll t=0;
    for(int i=0;i<5;i++)
        t=t*10+s[i]-'0';
    ll tt=1;
    for(int i=0;i<5;i++)
        tt=tt*t%100000;
    printf("%05I64d\n",tt);
    return 0;
}