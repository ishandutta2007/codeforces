#include <iostream>
#include <cstdio>
using namespace std;

int n;
string slo;

int main()
{
    cin >> n;
    cin >> slo;
    slo='#'+slo;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i+4*j<=n && slo[i]=='*' && slo[i+j]=='*' && slo[i+j*2]=='*' && slo[i+j*3]=='*' && slo[i+j*4]=='*')
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}