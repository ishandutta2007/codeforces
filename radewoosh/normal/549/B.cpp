#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

char wcz[107][107];

int tab[107];

vector <int> wyn;

int ilema[107];

int czy;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s", wcz[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
    }
    while(1)
    {
        czy=-1;
        for (int i=0; i<n; i++)
        {
            if (tab[i]==ilema[i])
            {
                czy=i;
                break;
            }
        }
        if (czy<0)
        break;
        wyn.push_back(czy);
        for (int i=0; i<n; i++)
        {
            if (wcz[czy][i]=='1')
            {
                ilema[i]++;
            }
        }
    }
    printf("%d\n", wyn.size());
    sort(wyn.begin(), wyn.end());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]+1);
    }
    return 0;
}