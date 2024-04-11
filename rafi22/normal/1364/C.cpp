#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,other=100007;
    cin>>n;
    int tab[n+7];
    int res[n+7];
    for(int i=1;i<=n;i++) cin>>tab[i];
    set <int> liczby;
    for(int i=0;i<=2*n;i++)
    {
        liczby.insert(i);
    }
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        liczby.erase(tab[i]);
    }
    res[1]=*liczby.begin();
    liczby.erase(liczby.begin());
    for(int i=2;i<=n;i++)
    {
        if(tab[i]!=tab[i-1]) res[i]=tab[i-1];
        else
        {
            res[i]=*liczby.begin();
            liczby.erase(liczby.begin());
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";


    return 0;
}