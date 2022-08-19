#include <bits/stdc++.h>
using namespace std;

int n;

string slo1, slo2;

int main()
{
    cin >> n >> slo1 >> slo2;
    if (slo2!="week")
    {
        if (n<=29)
        {
            printf("12\n");
            return 0;
        }
        if (n<=30)
        {
            printf("11\n");
            return 0;
        }
        if (n<=31)
        {
            printf("7\n");
            return 0;
        }
    }
    else
    {
        if (n!=5 && n!=6)
        {
            printf("52\n");
            return 0;
        }
        else
        {
            printf("53\n");
            return 0;
        }
    }
    return 0;
}