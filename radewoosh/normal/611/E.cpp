#include <bits/stdc++.h>
using namespace std;

int n;

int a, b, c;

int p1;
set < pair <int,int> > setel;

int wyn;

set < pair <int,int> >::iterator it;

int inf=1000000000;

pair <int,int> x;

int main()
{
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);

    if (a>c)
    swap(a, c);
    if (b>c)
    swap(b, c);
    if (a>b)
    swap(a, b);

    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p1);
        setel.insert(make_pair(p1, i));
    }

    while(!setel.empty())
    {
        it=setel.end();
        it--;
        if ((*it).first<=c)
        {
            wyn++;
            setel.erase(it);

            it=setel.upper_bound(make_pair(b, inf));
            if (it==setel.begin())
            {
                it=setel.upper_bound(make_pair(a+b, inf));
                if (it!=setel.begin())
                {
                    it--;
                    setel.erase(it);
                }
                continue;
            }

            it--;
            x=(*it);
            setel.erase(it);

            it=setel.upper_bound(make_pair(a, inf));
            if (it!=setel.begin())
            {
                it--;
                setel.erase(it);
            }
            else
            {
                setel.insert(x);
                it=setel.upper_bound(make_pair(a+b, inf));
                it--;
                setel.erase(it);
            }

            continue;
        }
        if ((*it).first<=a+b)
        {
            wyn++;

            setel.erase(it);

            it=setel.upper_bound(make_pair(c, inf));
            if (it!=setel.begin())
            {
                it--;
                setel.erase(it);
            }

            continue;
        }
        if ((*it).first<=a+c)
        {
            wyn++;

            setel.erase(it);

            it=setel.upper_bound(make_pair(b, inf));
            if (it!=setel.begin())
            {
                it--;
                setel.erase(it);
            }

            continue;
        }
        if ((*it).first<=b+c)
        {
            wyn++;

            setel.erase(it);

            it=setel.upper_bound(make_pair(a, inf));
            if (it!=setel.begin())
            {
                it--;
                setel.erase(it);
            }

            continue;
        }
        if ((*it).first<=a+b+c)
        {
            wyn++;

            setel.erase(it);

            continue;
        }
        printf("-1\n");
        return 0;
    }
    printf("%d\n", wyn);

    return 0;
}