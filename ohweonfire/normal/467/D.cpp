#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int maxn=500005;
typedef pair<pair<int,int>,int> pii;
map<string,int> has;
string essay[maxn];
priority_queue<pii,vector<pii>,greater<pii> > que;
int n,m,cnt,numr[maxn],numl[maxn];
bool use[maxn];
vector<int> g[maxn];
int Ind(string &s)
{
    for(int i=0;i<s.size();i++)
        if(s[i]>='A'&&s[i]<='Z')
            s[i]-='Z'-'z';
    if(has.find(s)==has.end())
    {
        int R=0;
        for(int i=0;i<s.size();i++)
            R+=(s[i]=='R'||s[i]=='r');
        que.push(mp(mp(R,s.size()),++cnt));
        has[s]=cnt;
        numr[cnt]=R;
        numl[cnt]=s.size();
    }
    return has[s];
}
void dijkstra()
{
    while(!que.empty())
    {
        int x=que.top().second;
        que.pop();
        if(use[x])
            continue;
        use[x]=true;
        for(int i=0;i<g[x].size();i++)
            if(numr[x]<numr[g[x][i]])
            {
                numl[g[x][i]]=numl[x];
                numr[g[x][i]]=numr[x];
                que.push(mp(mp(numr[x],numl[x]),g[x][i]));
            }
            else if(numr[x]==numr[g[x][i]]&&numl[x]<numl[g[x][i]])
            {
                numl[g[x][i]]=numl[x];
                que.push(mp(mp(numr[x],numl[x]),g[x][i]));
            }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>essay[i];
        Ind(essay[i]);
    }
    cin>>m;
    string x,y;
    while(m--)
    {
        cin>>x>>y;
        int xx=Ind(x),yy=Ind(y);
        g[yy].push_back(xx);
    }
    dijkstra();
    long long ansr=0,ansl=0;
    for(int i=1;i<=n;i++)
    {
        int t=Ind(essay[i]);
        ansr+=numr[t];
        ansl+=numl[t];
    }
    cout<<ansr<<' '<<ansl<<endl;
}