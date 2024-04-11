#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int n;
int sto[70000];
int war[70000];
priority_queue <pair <int,int> > kol;
vector <pair <int,int> > wek;
int v;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d", &sto[i], &war[i]);
        kol.push(make_pair(-sto[i], i));
    }
    while(!kol.empty())
    {
                       //printf("%d %d\n", kol.top().first, kol.top().second);
                       //system("pause");
                       v=kol.top().second;
                       if (kol.top().first==0)
                       {
                                              kol.pop();
                                              continue;
                       }
                       if (sto[v]!=-kol.top().first)
                       {
                                                   kol.pop();
                                                   continue;
                       }
                       kol.pop();
                       wek.push_back(make_pair(v, war[v]));
                       sto[v]--;
                       sto[war[v]]--;
                       kol.push(make_pair(-sto[war[v]], war[v]));
                       war[war[v]]^=v;
                       war[v]^=war[v];
    }
    printf("%d\n", wek.size());
    for (int i=0; i<wek.size(); i++)
    {
        printf("%d %d\n", wek[i].first, wek[i].second);
    }
    return 0;
}