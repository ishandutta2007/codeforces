#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

const int nax=2e5+5;
int a[nax];
bool done[nax];
int res[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        int n; cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) done[i]=false;
        vector<int> akt;
        for(int i=1;i<=n;i++)
        {
            if(done[i]==true) continue;
            akt.clear();
            akt.push_back(i);
            int j=a[i];
            while(j!=i)
            {
                akt.push_back(j);
                j=a[j];
            }
            for(int j=0;j<akt.size();j++)
            {
                done[akt[j]]=true;
                res[akt[j]]=akt.size();
            }
        }
        for(int i=1;i<=n;i++) cout<<res[i]<<" ";
        cout<<"\n";
    }
    return 0;
}