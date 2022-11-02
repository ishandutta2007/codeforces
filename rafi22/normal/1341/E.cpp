#include <bits/stdc++.h>

using namespace std;

int dis[10007][1007];
bool odw[10007][1007];
int tab[10007];
deque <pair<int,int> >kolejka;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,g,r;
    cin>>n>>m;
    int tab1[n];
    for(int i=0;i<m;i++) cin>>tab1[i];
    sort(tab1,tab1+m);
    for(int i=1;i<=m;i++) tab[i]=tab1[i-1];
    cin>>g>>r;
    kolejka.push_back(make_pair(1,0));
    int res=1000000007;
    while(kolejka.size()>0)
    {
        int p=kolejka[0].first;
        int t=kolejka[0].second;
        kolejka.pop_front();
        if(p==0||p==m+1)
        {
            continue;
        }
        if(t==g)
        {
            if(odw[p][0]==0)
            {
                dis[p][0]=dis[p][t]+1;
                kolejka.push_back(make_pair(p,0));
                odw[p][0]=1;
            }
        }
        if(t==0&&tab[m]-tab[p]<=g)
        {
            res=min(res,(g+r)*dis[p][t]+tab[m]-tab[p]);
        }
        int t1=t+tab[p]-tab[p-1];
        if(t1<=g&&!odw[p-1][t1])
        {
            kolejka.push_front(make_pair(p-1,t1));
            odw[p-1][t1]=1;
            dis[p-1][t1]=dis[p][t];
        }
        t1=t+tab[p+1]-tab[p];
        if(t1<=g&&!odw[p+1][t1])
        {
            kolejka.push_front(make_pair(p+1,t1));
            odw[p+1][t1]=1;
            dis[p+1][t1]=dis[p][t];
        }
    }
    if(res==1000000007) cout<<-1;
    else cout<<res;


    return 0;
}