#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int ile[520];
char wcz[1000007];

vector <long long> wek;
long long wyn;

long long x;

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", wcz);
    for (int i=0; i<n; i++)
    {
        ile[wcz[i]]++;
    }
    for (int i=0; i<=500; i++)
    {
        if (ile[i])
        {
            wek.push_back(ile[i]);
        }
    }
    sort(wek.begin(), wek.end());
    while(k)
    {
        x=min(k, (int)wek.back());
        k-=x;
        wek.pop_back();
        wyn+=x*x;
    }
    printf("%lld", wyn);
    return 0;
}