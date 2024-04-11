#include <bits/stdc++.h>
#define ll long long int
#define pb push_back


using namespace std;

vector<char> s = {'c','o','d','e','f','o','r','c','e','s'};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k; cin>>k;
    vector<ll> ile;
    for(int i=0;i<10;i++) ile.pb(1);
    ll ilo = 1;
    while(ilo<k)
    {
        sort(ile.begin(),ile.end());
        ilo /= ile[0];
        ile[0]++;
        ilo *= ile[0];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<ile[i];j++)
        {
            cout<<s[i];
        }
    }


    return 0;
}