#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
using namespace std;
vector<int> costE;
vector<pair<int,int> > cost;
vector<vector<pair<int,ii>> > g;
set<pair<int,int> > q;
int INFI=9e18;

void updateC(int cur){
    int c=cost[cur].x;
    for(auto v:g[cur]){
        if(cost[v.x].x>c+v.y.x) {
            q.erase(mp(cost[v.x].x,v.x));
            cost[v.x]=mp(c+v.y.x,v.y.y);
            q.insert(mp(cost[v.x].x,v.x));
        }
        else if(cost[v.x].x==c+v.y.x){
            if (costE[cost[v.x].y]>costE[v.y.y]){
                cost[v.x]=mp(cost[v.x].x,v.y.y);
            }
        }
    }
}


int32_t main()
{
    int n,m,a,b,c,s;
    int sum=0;
    int cur;
    cin >> n >> m;
    g.resize(n);
    cost.resize(n);
    costE.resize(m);
    for(int i=0;i<m;i++){
        cin >>a>>b>>c; a--;b--;
        g[a].pb(mp(b,mp(c,i)));
        g[b].pb(mp(a,mp(c,i)));
        costE[i]=c;
    }
    cin >>s;s--;
    q.insert(mp(0,s));
    cost[s]=mp(0,-1);
    for(int i=0;i<n;i++){
        if (i!=s){
            q.insert(mp(INFI,i));
            cost[i]=mp(INFI,-1);
        }
    }
    while (q.size()>0){
        cur=(*q.begin()).y;
        q.erase(q.begin());
        updateC(cur);
    }
    for (int i=0;i<n;i++){
        if (i!=s) sum+=costE[cost[i].y];
    }
    cout << sum<<endl;
    for (int i=0;i<n;i++){
        if (i!=s) cout << (cost[i].y+1)<<" ";
    }
    cout<<endl;
    return 0;
}