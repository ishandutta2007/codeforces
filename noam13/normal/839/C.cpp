#include <bits/stdc++.h>
//#define int long long
//#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,long long>
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;

vector<vector<int> > g;


long double heightOfLeavs(int cur){
    if (g[cur].size()==0) {
        return 0;
    }
    long double sum=0;
    int v;
    for (int i=0;i<g[cur].size();i++) {
        v=g[cur][i];
        g[v].erase(find(all(g[v]),cur));
        sum+=heightOfLeavs(v);
    }
    return ((sum/g[cur].size())+1);
}
int main()
{
    cout << fixed << showpoint << setprecision(15);
    int n,x,y;
    long double avg;
    cin >> n;
    g.resize(n);
    for (int i=0;i<n-1;i++){
        cin >> x>> y; x--;y--;
        g[x].pb(y); g[y].pb(x);
    }
    cout <<heightOfLeavs(0)<<endl;
    return 0;
}