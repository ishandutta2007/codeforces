#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int number=0;
    while(n>=100)
    {
        number++;
        n-=100;
    }
    while(n>=20)
    {
        number++;
        n-=20;
    }
    while(n>=10)
    {
        number++;
        n-=10;
    }
    while(n>=5)
    {
        number++;
        n-=5;
    }
    while(n>=1)
    {
        number++;
        n-=1;
    }
    printf("%i\n",number);
    return 0;
}