#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;

string aa, bb;

int roz;

int main()
{
    cin >> aa >> bb;
    n=aa.size();
    for (int i=0; i<n; i++)
    {
        roz+=(aa[i]!=bb[i]);
    }
    if (roz&1)
    {
        printf("impossible");
        return 0;
    }
    roz>>=1;
    for (int i=0; i<n; i++)
    {
        if (aa[i]!=bb[i] && roz)
        {
            aa[i]=bb[i];
            roz--;
        }
    }
    cout << aa;
    return 0;
}