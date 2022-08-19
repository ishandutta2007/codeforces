#include <bits/stdc++.h>
using namespace std;

int n;

long long m;

pair <long long, long long> tab[1000007];

int wyn;

priority_queue <long long> jesz, juz;

long long sta[1000007];
long long dood;

void aktu()
{
    if (jesz.empty())
        return;
    while(!juz.empty() && juz.top()>-jesz.top())
    {
        long long x=-jesz.top();
        long long y=juz.top();
        dood-=x;
        dood+=y;
        juz.pop();
        jesz.pop();
        juz.push(x);
        jesz.push(-y);
    }
    while(!jesz.empty() && -jesz.top()<=dood)
    {
        dood-=-jesz.top();
        juz.push(-jesz.top());
        jesz.pop();
    }
}

int main()
{
    scanf("%d", &n);
    n--;
    scanf("%lld%lld", &m, &tab[0].first);
    for (int i=1; i<=n; i++)
        scanf("%lld%lld", &tab[i].first, &tab[i].second);
    sort(tab+1, tab+1+n);
    for (int i=n; i; i--)
        if (m>=tab[i].first)
            wyn++;
    for (int i=1; i<=n; i++)
    {
        sta[i]=max((long long)0, m-tab[i].first);
    }
    for (int i=n; i; i--)
    {
        dood+=sta[i]-sta[i+1];
        aktu();
        if (m>=tab[i].first)
        {
            wyn=max(wyn, i+(int)juz.size());
            //printf("%d: %d %lld\n", i, (int)juz.size(), dood);
        }
        jesz.push(-(tab[i].second+1-tab[i].first));
        aktu();
    }
    dood+=m-sta[1];
    aktu();
    wyn=max(wyn, (int)juz.size());
    printf("%d\n", n+1-wyn);
    return 0;
}