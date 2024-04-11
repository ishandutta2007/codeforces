#include <bits/stdc++.h>
using namespace std;

int n;

long long a, b;
long long tab1[100007];
long long tab2[100007];

vector <int> jed;
vector <int> dwa;

bool mniej1(int x, int y)
{
    if (tab1[x]*a+tab2[x]!=tab1[y]*a+tab2[y])
    return tab1[x]*a+tab2[x]<tab1[y]*a+tab2[y];
    return 0;
}

bool mniej2(int x, int y)
{
    if (tab1[x]*b+tab2[x]!=tab1[y]*b+tab2[y])
    return tab1[x]*b+tab2[x]<tab1[y]*b+tab2[y];
    return mniej1(x, y);
}

int main()
{
    scanf("%d", &n);
    scanf("%lld%lld", &a, &b);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &tab1[i], &tab2[i]);
        jed.push_back(i);
        dwa.push_back(i);
    }
    sort(dwa.begin(), dwa.end(), mniej2);
    for (int i=0; i<dwa.size()-1; i++)
    {
        if (mniej1(dwa[i+1], dwa[i]))
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}