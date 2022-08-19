#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> s;

int n;

map <int,int> mapa;

int p1, p2;

vector <pair <int,int> > wek;

long long wyn;

int abs(int v)
{
    return max(v, -v);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &p1, &p2);
        if (!mapa[p1])
        mapa[p1]=p1;
        if (!mapa[p2])
        mapa[p2]=p2;
        swap(mapa[p1], mapa[p2]);
    }
    for (map <int,int>::iterator it=mapa.begin(); it!=mapa.end(); it++)
    {
        if (it->first==it->second)
        continue;
        wek.push_back(make_pair( it->first , it->second ));
    }
    if (wek.empty())
    {
        printf("0");
        return 0;
    }
    for (int i=0; i<wek.size(); i++)
    {
        s.insert(wek[i].second);
        wyn+=s.size()-s.order_of_key(wek[i].second)-1;
        //printf("%d %d    %lld\n", wek[i].first, wek[i].second, wyn);
    }
    printf("\n");
    for (int i=0; i<wek.size(); i++)
    {
        p1=s.order_of_key(wek[i].first);
        p2=s.order_of_key(wek[i].second);
        //printf("%d\n%d\n", p1, p2);
        wyn+=abs(wek[i].first-wek[i].second)-abs(p1-p2);
        //printf("%d %d    %lld\n", wek[i].first, wek[i].second, wyn);
    }
    cout << wyn;
    return 0;
}