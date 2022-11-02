#include <bits/stdc++.h>

using namespace std;

vector <int> G[500007];
deque <int> kolejka;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin>>n>>m;
    pair<int,int> val[n];
    val[0]=make_pair(0,0);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        val[i]=make_pair(a,i);
    }
    bool ok=1;
    set <int> dif;
    for(int i=1;i<=n;i++)
    {
        dif.clear();
        for(int j=0;j<G[i].size();j++)
        {
            dif.insert(val[G[i][j]].first);
            if(val[i].first==val[G[i][j]].first) ok=0;
        }
        dif.insert(10e8+7);
        dif.insert(0);
        int num;
        for(set<int>::iterator it=dif.begin();it!=--dif.end();it++)
        {
            int st=*it;
            it++;
            int nd=*it;
            it--;
            if(nd-1>st)
            {
                num=st+1;
                break;
            }
        }
        if(num<val[i].first) ok=0;
    }
    if(!ok) cout<<-1<<endl;
    else
    {
        sort(val,val+n+1);
        for(int i=1;i<=n;i++)
        {
            cout<<val[i].second<<" ";
        }
    }

    return 0;
}