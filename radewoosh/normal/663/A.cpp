#include <bits/stdc++.h>
using namespace std;

long long n;

string wcz;

vector <int> plu;

long long wyn[1007];

vector <int> dod, uje;

long long a, b;

long long r;

int main()
{
    cin >> wcz;
    plu.push_back(1);
    dod.push_back(1);
    while(1)
    {
        cin >> wcz;
        if (wcz=="=")
        {
            cin >> n;
            break;
        }
        else
        {
            if (wcz=="+")
            {
                plu.push_back(1);
                dod.push_back(plu.size());
            }
            if (wcz=="-")
            {
                plu.push_back(0);
                uje.push_back(plu.size());
            }
            cin >> wcz;
        }
    }
    for (long long i=0; i<=100*n; i++)
    {
        a=i+n;
        b=i;
        if (a>=dod.size() && a<=dod.size()*n && b>=uje.size() && b<=uje.size()*n)
        {
            for (int j=0; j<dod.size(); j++)
            {
                wyn[dod[j]]++;
                a--;
            }
            for (int j=0; j<dod.size(); j++)
            {
                r=min(a, n-1);
                wyn[dod[j]]+=r;
                a-=r;
            }
            for (int j=0; j<uje.size(); j++)
            {
                wyn[uje[j]]++;
                b--;
            }
            for (int j=0; j<uje.size(); j++)
            {
                r=min(b, n-1);
                wyn[uje[j]]+=r;
                b-=r;
            }
            printf("Possible\n");
            for (int i=1; i<=plu.size(); i++)
            {
                printf("%lld ", wyn[i]);
                if (i!=plu.size())
                {
                    if (plu[i])
                    printf("+ ");
                    else
                    printf("- ");
                }
                else
                printf("= ");
            }
            printf("%lld\n", n);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}