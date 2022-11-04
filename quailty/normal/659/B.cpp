#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10005;
vector<pair<int,string> >v[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string str;
        int r,sc;
        cin>>str>>r>>sc;
        v[r].push_back(make_pair(sc,str));
    }
    for(int i=1;i<=m;i++)
        sort(v[i].begin(),v[i].end(),greater<pair<int,string> >());
    for(int i=1;i<=m;i++)
    {
        if((int)v[i].size()==2 || v[i][2].first<v[i][1].first)
            cout<<v[i][0].second<<" "<<v[i][1].second<<endl;
        else cout<<"?"<<endl;
    }
    return 0;
}