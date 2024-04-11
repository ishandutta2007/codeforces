#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string slo;

vector <int> jed, dwa;

int main()
{
    cin >> slo;
    for (int i=1; i<slo.size(); i++)
    {
        if (slo[i]=='A' && slo[i-1]=='B')
        {
            jed.push_back(i-1);
        }
        if (slo[i]=='B' && slo[i-1]=='A')
        {
            dwa.push_back(i-1);
        }
    }
    if (jed.empty() || dwa.empty())
    {
        printf("NO");
        return 0;
    }
    if (jed[0]+1<dwa.back() || dwa[0]+1<jed.back())
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}