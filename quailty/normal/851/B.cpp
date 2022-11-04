#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll p[6],d[3];
    for(int i=0;i<6;i++)
        scanf("%lld",&p[i]);
    d[0]=(p[2]-p[0])*(p[2]-p[0])+(p[3]-p[1])*(p[3]-p[1]);
    d[1]=(p[4]-p[2])*(p[4]-p[2])+(p[5]-p[3])*(p[5]-p[3]);
    d[2]=(p[4]-p[0])*(p[4]-p[0])+(p[5]-p[1])*(p[5]-p[1]);
    printf("%s\n",(d[0]==d[1] && d[2]!=4*d[0] ? "Yes" : "No"));
    return 0;
}