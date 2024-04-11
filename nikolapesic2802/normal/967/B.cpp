#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,a,b;
    scanf("%i %i %i",&n,&a,&b);
    int s[n];
    int prva;
    long long sum=0;
    scanf("%i",&prva);
    sum+=prva;
    for(int i=0;i<n-1;i++)
    {
        scanf("%i",&s[i]);
        sum+=s[i];
    }
    int broj=0;
    sort(s,s+n-1);
    int sta=n-2;
    //printf("%i",s[sta]);
    double d=(double)prva*(double)a/sum;
    while(d<b)
    {
        sum-=s[sta];
        sta--;
        broj++;
        d=(double)prva*(double)a/sum;
    }
    printf("%i",broj);
    return 0;
}