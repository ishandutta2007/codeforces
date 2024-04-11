#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a;
    scanf("%i %i %i",&n,&m,&a);
    int x=n/a;
    int y=m/a;
    if(n%a!=0)
    {
        x++;
    }
    if(m%a!=0)
    {
        y++;
    }
    //printf("%i %i\n",x,y);
    cout<<(long long)x*y;
    return 0;
}