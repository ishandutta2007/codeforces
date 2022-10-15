#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define Q 10020
using namespace std;
 
long long n[Q], m[Q], k[Q];
 
int main(void)
{
    int q;
    int i;
 
    scanf("%d", &q);
    for(i = 0; i < q; i ++)
    {
        scanf("%I64d %I64d %I64d", &n[i], &m[i], &k[i]);
 
        if(n[i] < m[i])
            swap(n[i], m[i]);
        if((n[i] & 1) ^ (m[i] & 1))
        {
            -- n[i];
            -- k[i];
        }
        else
            if((n[i] & 1) ^ (k[i] & 1))
            {
                -- n[i];
                -- m[i];
                k[i] -= 2;
            }
 
        printf("%I64d\n", n[i] <= k[i] ? k[i] : -1);
    }
 
    return 0;
}