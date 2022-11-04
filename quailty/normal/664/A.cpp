#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
char a[MAXN],b[MAXN];
int main()
{
    scanf("%s%s",a,b);
    printf("%s",strcmp(a,b) ? "1" : a);
    return 0;
}