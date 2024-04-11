#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,k,mx=0;
        set <int> rozne;
        set <int> niema;
        map <int,int> mapa;
        cin>>n>>k;
        for(int i=1;i<=n;i++) niema.insert(i);
        int tab[n];
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            rozne.insert(tab[i]);
            niema.erase(tab[i]);
            mapa[tab[i]]++;
            mx=max(mx,mapa[tab[i]]);
        }
        if(rozne.size()>k) cout<<-1;
        else
        {
            if(mx==100)
            {
                cout<<n*k<<endl;
                for(int l=0; l<n; l++)
                {
                    for(set<int>::iterator it=rozne.begin(); it!=rozne.end(); it++)
                    {
                        cout<<*it<<" ";
                    }
                    set<int>::iterator it=niema.begin();
                    for(int i=rozne.size(); i<k; i++)
                    {
                        cout<<*it<<" ";
                        it++;
                    }
                }
            }
            else
            {
                cout<<n*k<<endl;
                for(int l=0; l<n; l++)
                {
                    for(set<int>::iterator it=rozne.begin(); it!=rozne.end(); it++)
                    {
                        cout<<*it<<" ";
                    }
                    set<int>::iterator it=niema.begin();
                    for(int i=rozne.size(); i<k; i++)
                    {
                        cout<<*it<<" ";
                        it++;
                    }
                }
            }

        }
        cout<<endl;


    }
    return 0;
}