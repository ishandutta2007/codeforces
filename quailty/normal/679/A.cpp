#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
bool get()
{
    char s[5];
    scanf("%s",s);
    return *s=='y';
}
void prime()
{
    printf("prime\n"),fflush(stdout);
    exit(0);
}
bool compo()
{
    printf("composite\n"),fflush(stdout);
    exit(0);
}
void check2(int x)
{
    for(int i=2;x*i<=100;i++)
        if(is_prime(i))
        {
            printf("%d\n",x*i),fflush(stdout);
            if(get())compo();
        }
    prime();
}
void check1()
{
    for(int i=2;i<=10;i++)
        if(is_prime(i))
        {
            printf("%d\n",i),fflush(stdout);
            if(get())check2(i);
        }
    prime();
}
int main()
{
    check1();
    return 0;
}