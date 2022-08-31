#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int k;

int n;

vector < pair <int,int> > kra;

vector <int> jakie;

int main()
{
    scanf("%d", &k);
    if (!(k&1))
    {
        printf("NO");
        return 0;
    }
    n=2;
    kra.push_back(make_pair(1, 2));
    for (int i=1; i<=(k>>1); i++)
    {
        jakie.clear();
        for (int j=1; j<=k+1; j++)
        {
            jakie.push_back(n+j);
        }
        for (int j=0; j<jakie.size(); j++)
        {
            for (int l=j+1; l<jakie.size(); l++)
            {
                if (l==1)
                {
                    continue;
                }
                kra.push_back(make_pair(jakie[j], jakie[l]));
            }
        }
        kra.push_back(make_pair(1, jakie[0]));
        kra.push_back(make_pair(1, jakie[1]));
        n+=jakie.size();
    }
    for (int i=1; i<=(k>>1); i++)
    {
        jakie.clear();
        for (int j=1; j<=k+1; j++)
        {
            jakie.push_back(n+j);
        }
        for (int j=0; j<jakie.size(); j++)
        {
            for (int l=j+1; l<jakie.size(); l++)
            {
                if (l==1)
                {
                    continue;
                }
                kra.push_back(make_pair(jakie[j], jakie[l]));
            }
        }
        kra.push_back(make_pair(2, jakie[0]));
        kra.push_back(make_pair(2, jakie[1]));
        n+=jakie.size();
    }
    printf("YES\n");
    printf("%d %d\n", n, kra.size());
    for (int i=0; i<kra.size(); i++)
    {
        printf("%d %d\n", kra[i].first, kra[i].second);
    }
    return 0;
}