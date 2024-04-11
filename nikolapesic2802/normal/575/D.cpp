#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int N=1000;
    printf("%i\n",2*N);
    for(int i=1;i<=N;i++)
    {
        printf("%i %i %i %i\n",i,1,i,2);
    }
    for(int i=N;i>=1;i--)
    {
        printf("%i %i %i %i\n",i,1,i,2);
    }
    return 0;
}