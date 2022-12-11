#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
vector<ll> g[maxn];
ll sum[maxn];
int n;
void init(){
    cin>>n;
    for(int i = 0; i <= n; ++i) g[i].clear();
    for(int i = 0; i < n; ++i){
        int m; ll p;
        scanf("%d%I64d", &m, &p);
        g[m].push_back(p);
    }
    sum[0] = g[0].size();
    for(int i = 1; i <= n; ++i){
        sum[i] = g[i].size() + sum[i-1];
        //cout<<"i:"<<i<<" sum:"<<sum[i]<<endl;
    }
}
priority_queue<ll, vector<ll> ,greater<ll> > q;
void sol(){
    while(q.size()) q.pop();
    ll ans = 0;
    int res = 0;
    for(int i = n; i > 0; --i){
        for(int j = 0; j < g[i].size(); ++j) q.push(g[i][j]);
        int ex = i - sum[i-1] - res;
        //cout<<"i:"<<i<<" ex:"<<ex<<endl;
        if(ex <= 0) continue;
        res += ex;
        while(ex--){
//            cout<<"ex:"<<ex<<endl;
//            cout<<"sz:"<<q.size()<<endl;
            ans += q.top(); q.pop();
        }
    }printf("%I64d\n", ans);
}
int main()
{
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
}
/*
1
7
0 1
3 1
1 1
6 1
1 1
4 1
4 1
*/