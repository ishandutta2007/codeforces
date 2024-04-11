#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

vector <long long> jed, dwa;

int main()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    for (int i=0; i<=60000; i++)
    {
        jed.push_back(a+i*c);
    }
    for (long long i=0; b-50000*i*c>-2000000007 && b-50000*i*c<2000000007 && i<=50000; i++)
    {
        dwa.push_back(b-50000*i*c);
    }
    sort(jed.begin(), jed.end());
    sort(dwa.begin(), dwa.end());
    while(!jed.empty() && !dwa.empty())
    {
        if (jed.back()<dwa.back())
        {
            dwa.pop_back();
            continue;
        }
        if (jed.back()>dwa.back())
        {
            jed.pop_back();
            continue;
        }
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}