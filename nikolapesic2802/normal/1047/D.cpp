#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    if(n>m)
        swap(n,m);
    if(n==1)
    {
        if(m%6==2)
        {
            printf("%i\n",m-2);
            return 0;
        }
        if(m%6==3)
        {
            printf("%i\n",m-3);
            return 0;
        }
        if(m%6==4)
        {
            printf("%i\n",m-2);
            return 0;
        }
    }
    if(n==2)
    {
        if(m==2)
        {
            printf("0\n");
            return 0;
        }
        if(m==3)
        {
            printf("4\n");
            return 0;
        }
        if(m==7)
        {
            printf("12\n");
            return 0;
        }
    }
    if(((ll)n*(ll)m)%2==1)
    {
        printf("%lld\n",(ll)n*(ll)m-1);
    }
    else
    {
        printf("%lld\n",(ll)n*(ll)m);
    }
    return 0;
}