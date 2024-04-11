#include <bits/stdc++.h>

using namespace std;
int n,m;
vector <pair<int,int> > G[100007];
map <int,int> mapa[100007];
bool odw[100007];
int val[100007];
vector <int> path;
int a[100007];
int b[100007];
vector <pair<int,int>> loops;

void loop(int v,int c)
{
    val[v]=c;
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u.first])
        {
            loop(u.first,u.second-val[v]);
        }
        else
        {
            if(val[v]+val[u.first]!=u.second)
            {
                cout<<"NO";
                exit(0);
            }
        }

    }
}
void dfs(int v)
{
    path.push_back(v);
    for(auto u:G[v])
    {
        int ap=-a[v],bp=u.second-b[v];
        if(!odw[u.first])
        {
            odw[u.first]=1;
            a[u.first]=ap;
            b[u.first]=bp;
            dfs(u.first);
        }
        else
        {
            if(ap==a[u.first]&&bp==b[u.first]) ;
            else if(ap==a[u.first]&&bp!=b[u.first])
            {
                cout<<"NO";
                exit(0);
            }
            else
            {
                int x=(bp-b[u.first])/(a[u.first]-ap);
                for(int i=0;i<path.size();i++)
                {
                    b[path[i]]=a[path[i]]*x+b[path[i]];
                    a[path[i]]=0;
                }
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int x,y,z;
    bool leave=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        z*=2;
        if(x==y) loops.push_back({x,z});
        G[x].push_back({y,z});
        G[y].push_back({x,z});
        if(mapa[min(x,y)][max(x,y)]!=0&&mapa[min(x,y)][max(x,y)]!=z&&!leave)
        {
            cout<<"NO";
            leave=1;
        }
        mapa[min(x,y)][max(x,y)]=z;
    }
    if(leave) return 0;
    for(int i=0;i<loops.size();i++) loop(loops[i].first,loops[i].second/2);
    for(int i=1;i<=n;i++)
    {
        if(G[i].empty())
        {
            val[i]=0;
            odw[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        path.clear();
        if(!odw[i])
        {
            odw[i]=1;
            a[i]=1;
            dfs(i);
            if(a[i]!=0)
            {
                vector <int> vec;
                for(int i=0;i<path.size();i++)
                {
                    vec.push_back((-a[path[i]])*b[path[i]]);
                   // cout<<vec.back()<<" ";
                }
              //  cout<<endl;
                sort(vec.begin(),vec.end());
                int x;
                if(vec.size()%2)
                    x=vec[vec.size()/2];
                else x=(vec[vec.size()/2-1]+vec[vec.size()/2])/2;
                //cout<<x<<endl;
                for(int i=0;i<path.size();i++) b[path[i]]=a[path[i]]*x+b[path[i]];
            }
            for(int i=0;i<path.size();i++) val[path[i]]=b[path[i]];
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<((double)val[i])/2<<" ";
    }

    return 0;
}