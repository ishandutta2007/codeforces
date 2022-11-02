#include <bits/stdc++.h>

using namespace std;

vector <int> G[1007];
bool odw[1007];
int roz[1007];
int dep[1007];

void dfs(int v,int o)
{
    odw[v]=1;
    roz[v]=1;
    dep[v]=dep[o]+1;
    for(int i=0;i<G[v].size();i++)
    {
        if(!odw[G[v][i]])
        {
            dfs(G[v][i],v);
            roz[v]+=roz[G[v][i]];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
       /* long long n,x,a,p=0,np=0;
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0) p++;
            else np++;
        }
        if(np%2==0) np--;
        if(np>0&&p+np>=x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;*/
        int n,x,a,b;
        cin>>n>>x;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool w=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                odw[j]=0;
                dep[j]=0;
                roz[j]=0;
            }
            dep[0]=-1;
            dfs(i,0);
            int q=(n-roz[x]);
            roz[x]--;

            if(roz[x]==0||(n-1)%2==1) w=1;
        }
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
        }
        if(w) cout<<"Ayush"<<endl;
        else cout<<"Ashish"<<endl;

    }
    return 0;
}