#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h> 
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

long long bigmod(long long a)
{
    long long tmp;
    if (a==0)
        return 1;
    else if (a%2==0)
    {
        tmp=bigmod(a/2);
        return (tmp*tmp)%1000000007;
    }
    else
    {
        tmp=bigmod(a/2);
        return (2*tmp*tmp)%1000000007;
    }
}
int main()
{
    long long n;
    scanf("%I64d",&n);
    if (n==0)
        printf("1\n");
    else
    {
        long long tmp;
        tmp=bigmod(n-1);
        printf("%I64d\n",(tmp*(((tmp*2)%1000000007)+1))%1000000007);
    }
}