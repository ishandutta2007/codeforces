#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char ty[5];
    scanf("%s",ty);
    if(ty[0]=='a' || ty[0]=='h')
        printf("%d",(ty[1]=='1' || ty[1]=='8' ? 3 : 5));
    else
        printf("%d",(ty[1]=='1' || ty[1]=='8' ? 5 : 8));
    return 0;
}