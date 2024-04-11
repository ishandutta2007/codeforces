#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> tab[N];
    long long int res=0;
    for(int i=1;i<=2*n;i++)
    {
        int x; cin>>x;
        tab[x].push_back(i);
    }
    res+=tab[1][0];
    res+=tab[1][1];
    res-=2;
    for(int i=2;i<=n;i++)
    {
        long long int a,b;
        a=abs(tab[i][0]-tab[i-1][0])+abs(tab[i][1]-tab[i-1][1]);
        b=abs(tab[i][0]-tab[i-1][1])+abs(tab[i][1]-tab[i-1][0]);
        res+=min(a,b);
    }
    cout<<res;
    return 0;
}