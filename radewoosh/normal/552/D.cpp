#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector < pair <int,int> > tab;
int p1, p2;

long long wyn;
long long iles;
long long ost;

pair <int,int> x;

int ilo(pair <int,int> s, pair <int,int> a, pair <int,int> b)
{
    return (a.first-s.first)*(b.second-s.second)-(b.first-s.first)*(a.second-s.second);
}

bool mniej(pair <int,int> a, pair <int,int> b)
{
    return ilo(x, a, b)<0;
}

int main()
{
    scanf("%d", &n);
    iles=n;
    iles*=n-1;
    iles*=n-2;
    iles/=6;
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &p1 , &p2);
        tab.push_back(make_pair(p1, p2));
    }
    sort(tab.begin(), tab.end());
    while(tab.size()>=3)
    {
        sort(tab.begin(), tab.end());
        x=tab.back();
        tab.pop_back();
        sort(tab.begin(), tab.end(), mniej);
        ost=0;
        for (int i=0; i<tab.size(); i++)
        {
            if (i==tab.size()-1 || ilo(x, tab[i], tab[i+1]))
            {
                wyn+=((i-ost)*(i-ost+1))/2;
                ost=i+1;
            }
        }
    }
    printf("%lld", iles-wyn);
    return 0;
}