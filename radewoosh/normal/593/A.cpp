#include <bits/stdc++.h>
using namespace std;

int n;

string slo[107];
int d[107];

set <char> sety[107];

int wyn;
int aktu;

set <char> ter;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> slo[i];
        d[i]=slo[i].size();
        for (int j=0; j<slo[i].size(); j++)
        {
            sety[i].insert(slo[i][j]);
        }
    }
    for (char i='a'; i<='z'; i++)
    {
        for (int j=i+1; j<='z'; j++)
        {
            ter.clear();
            ter.insert(i);
            ter.insert(j);
            aktu=0;
            for (int l=1; l<=n; l++)
            {
                if (sety[l]==ter || (sety[l].size()==1 && (slo[l][0]==i || slo[l][0]==j)))
                {
                    aktu+=d[l];
                }
            }
            wyn=max(wyn, aktu);
        }
    }
    printf("%d\n", wyn);
    return 0;
}