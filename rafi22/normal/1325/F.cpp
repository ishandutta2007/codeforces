    #include <bits/stdc++.h>
     
    using namespace std;
     
    vector <int> G[100007];
    int stopien[100007];
    int ojciec[100007];
    int root;
    int n,m,a,b;
    bool odw[100007];
    bool taken[100007];
    bool found;
     
    void dfstree(int v,int o)
    {
        odw[v]=1;
        ojciec[v]=o;
        stopien[v]=stopien[o]+1;
        for(int i=0;i<G[v].size();i++)
        {
            if(!odw[G[v][i]])
            {
                dfstree(G[v][i],v);
            }
            else
            {
                if(G[v][i]!=o)
                {
                    if(!found)
                    {
                        if(stopien[v]-stopien[G[v][i]]+1>=root)
                        {
                            found=1;
                            cout<<2<<endl<<stopien[v]-stopien[G[v][i]]+1<<endl;
                            int u=v;
                            while(true)
                            {
                                cout<<u<<" ";
                                if(u==G[v][i])
                                    break;
                                u=ojciec[u];
                            }
                        }
                    }
                }
            }
        }
        if(!taken[v])
        {
            for(int i=0;i<G[v].size();i++)
            {
                taken[G[v][i]]=1;
            }
        }
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
     
        cin>>n>>m;
        while (root*root<n)
            root++;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfstree(1,0);
        if(!found)
        {
            cout<<1<<endl;
            for(int i=1;root;i++)
            {
                if(!taken[i])
                {
                    root--;
                    cout<<i<<" ";
                }
            }
        }
        return 0;
    }