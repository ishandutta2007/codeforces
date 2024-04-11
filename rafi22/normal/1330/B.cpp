    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        int t,n,a;
        cin>>t;
        vector <int> tab;
        vector <int> res;
        unordered_map <int,int> howmuch1;
        unordered_map <int,int> howmuch2;
        set<int> missing1;
        set<int> missing2;
        set <int> nope1;
        set <int> nope2;
        for(int i=0;i<t;i++)
        {
            tab.clear();
            res.clear();
            missing1.clear();
            missing2.clear();
            howmuch2.clear();
            howmuch1.clear();
            nope2.clear();
            nope1.clear();
            cin>>n;
     
            for(int j=0;j<n;j++)
            {
                cin>>a;
                tab.push_back(a);
                if(j>0)
                {
                    howmuch2[a]++;
                    if(howmuch2[a]>=2) nope2.insert(a);
                    missing2.insert(a);
                }
     
            }
            howmuch1[tab[0]]++;
            missing1.insert(tab[0]);
            for(int j=1; j<n; j++)
            {
                if(*--missing1.end()==missing1.size()&&*--missing2.end()==missing2.size()&&nope1.size()==0&&nope2.size()==0)
                {
                    res.push_back(j);
                }
                missing1.insert(tab[j]);
                howmuch1[tab[j]]++;
                if(howmuch1[tab[j]]>=2) nope1.insert(a);
                howmuch2[tab[j]]--;
                if(howmuch2[tab[j]]==0) missing2.erase(tab[j]);
                else if(howmuch2[tab[j]]==1) nope2.erase(tab[j]);
            }
            cout<<res.size()<<'\n';
            for(int j=0;j<res.size();j++)
            {
                cout<<res[j]<<" "<<n-res[j]<<'\n';
            }
     
        }
        return 0;
    }