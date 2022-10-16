#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%I64d",&n);
    vector<int> broj;
    long long sum=0;
    long long tr=1;
    for(long long i=1;i<100000;i++)
    {
        sum+=tr;
        tr*=2;
        if(sum>=n)
        {
            printf("%I64d\n",i);
            return 0;
        }
    }
    return 0;
}