#include <bits/stdc++.h>
#define ll long long int
#define pb push_back


using namespace std;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int k = 8;
    k += (n) * 7;
    vector<pair<int,int> > a;
    a.pb({0,0});
    for(int i=1;i<=n+1;i++)
    {
        pair<int,int> akt = a.back();
        a.pb({akt.first+1,akt.second});
        a.pb({akt.first+2,akt.second});
        a.pb({akt.first,akt.second+1});
        a.pb({akt.first,akt.second+2});
        a.pb({akt.first+2,akt.second+1});
        a.pb({akt.first+1,akt.second+2});
        a.pb({akt.first+2,akt.second+2});
    }
    cout<<k<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    return 0;
}