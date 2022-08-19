#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

string slo;

int main()
{
    cin >> slo;
    for (int i=0; i<slo.size(); i++)
    {
        if (slo[i]=='0' || slo[i]=='8')
        {
            printf("YES\n%d", slo[i]-'0');
            return 0;
        }
    }
    for (int i=0; i<slo.size(); i++)
    {
        for (int j=i+1; j<slo.size(); j++)
        {
            if (!(((slo[i]-'0')*10+(slo[j]-'0'))%8))
            {
                printf("YES\n%d%d", slo[i]-'0', slo[j]-'0');
                return 0;
            }
        }
    }
    for (int i=0; i<slo.size(); i++)
    {
        for (int j=i+1; j<slo.size(); j++)
        {
            for (int l=j+1; l<slo.size(); l++)
            {
                if (!(((slo[i]-'0')*100+(slo[j]-'0')*10+(slo[l]-'0'))%8))
                {
                    printf("YES\n%d%d%d", slo[i]-'0', slo[j]-'0', slo[l]-'0');
                    return 0;
                }
            }
        }
    }
    printf("NO");
    return 0;
}