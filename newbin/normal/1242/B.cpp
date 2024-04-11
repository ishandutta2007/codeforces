#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
set<int> s1, s2;
int n, m;
vector<int> g[maxn];
queue<int> q;
int main()
{
    int ans = 0;
    cin>>n>>m;
    while(m--){
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    s1.clear(); s2.clear();
    set<int> ::iterator it;
    for(int i = 2; i <= n; ++i) s1.insert(i);
    q.push(1);
    while(s1.size()){
        while(q.size()){
            int u = q.front();q.pop();
            for(int i = 0; i < g[u].size(); ++i){
                int v = g[u][i];
                if(s1.count(v)){
                    s1.erase(v);
                    s2.insert(v);
                }
            }
            for(it = s1.begin(); it!=s1.end(); ++it){
                q.push(*it);
            }
            swap(s1, s2);
            s2.clear();
        }
        if(s1.size()){
            int t = *s1.begin(); s1.erase(t); q.push(t); ans++;
        }
        else break;
    }
    cout<<ans<<endl;
}