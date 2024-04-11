#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int tab[n];
        vector <int> zb;
        vector <int> zb1;
        for(int i=0;i<n;i++) cin>>tab[i];
        for(int i=0;i<n;i++) zb.push_back(tab[i]);
        sort(zb.begin(),zb.end());
        bool b=0;
        for(int j=1;j<=1024;j++)
        {
            zb1.clear();
            for(int i=0;i<n;i++) zb1.push_back(tab[i]^j);
            sort(zb1.begin(),zb1.end());
            bool ok=1;
            for(int i=0;i<n;i++)
            {
                if(zb[i]!=zb1[i]) ok=0;
            }
            if(ok)
            {
                cout<<j<<endl;
                b=1;
                break;
            }
        }
        if(!b) cout<<-1<<endl;

    }
    return 0;
}