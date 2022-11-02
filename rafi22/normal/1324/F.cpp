    #include <bits/stdc++.h>
     
    using namespace std;
     
    vector <int> G[200007];
    bool tab[200007];
    bool odw[200007];
    bool odw1[200007];
    int res[200007];
     
    void dfs(int v)
    {
        odw[v]=1;
        if(tab[v]) res[v]++;
        else res[v]--;
        //res[v]=tab[v];
        for(int i=0;i<G[v].size();i++)
        {
            if(!odw[G[v][i]])
            {
                dfs(G[v][i]);
                if(res[G[v][i]]>0) res[v]+=res[G[v][i]];
            }
        }
    }
    void dfs1(int v)
    {
        odw1[v]=1;
     
        //res[v]=tab[v];
        for(int i=0;i<G[v].size();i++)
        {
            if(!odw1[G[v][i]])
            {
                if(res[v]-max(0,res[G[v][i]])>0) res[G[v][i]]+=res[v]-max(0,res[G[v][i]]);
                dfs1(G[v][i]);
            }
        }
     
    }
     
    int main()
    {
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
        }
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1);
        dfs1(1);
        for(int i=1;i<=n;i++) cout<<res[i]<<" ";
        return 0;
    }