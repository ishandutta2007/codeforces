#include <bits/stdc++.h>
//#define int long long
//#define vi vector<int>
#define pb(x) push_back(x)
using namespace std;

string let;
vector<vector<int> > g;
vector<int> ml;
bool loop=false;
int updateC(int cur,char c){
    if (ml[cur]>-1) return ml[cur];
    if (ml[cur]==-2) {
        loop=true;
        return ml[cur];
    }
    ml[cur]=-2;
    int m=0;
    for (auto s : g[cur]){
        if (m<updateC(s,c)) m=updateC(s,c);
    }
    ml[cur]=(m+(let[cur]==c));
    return ml[cur];
}



int main()
{
    int n,m,x,y,maxl=0;
    cin >> n >>m;
    g.resize(n);
    ml.resize(n,-1);
    let.resize(n);
    cin >> let;
    for (int i=0;i<m;i++){
        cin >> x>> y; g[--x].pb(--y);
    }
    for(char c='a';c<='z' && !loop;c++){
        for(int i=0;i<n && !loop;i++){
            updateC(i,c);
        }
        for(int i=0;i<n && !loop;i++){
            maxl=max(ml[i],maxl);
        }
        for (int i=0;i<n;ml[i++]=-1);
    }
    if (loop) cout << -1<<endl;
    else cout << maxl<<endl;
    return 0;
}