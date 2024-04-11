#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;
ii operator+(ii a, ii b){
    return {a.x+b.x,a.y+b.y};
}
int n,m;
ii dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
vvb b;
vvi times;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>n>>m>>t;
    b.resize(n, vb(m)); times.resize(n, vi(m,-1));
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m) b[i][j] = s[j]-'0';
    }
    loop(i,0,n) loop(j,0,m){
        for(auto d:dir){
            int x = i + d.x, y = j + d.y;
            if (x>=0 && x<n && y>=0 && y<m && b[x][y]==b[i][j]) times[i][j] = 0;
        }
    }
    queue<ii> q;
    loop(i,0,n) loop(j,0,m) if (times[i][j]==0) q.push(ii(i,j));
    while(q.size()){
        ii cur = q.front(); q.pop();
        for(auto d:dir){
            ii nei = cur + d;
            if (nei.x>=0 && nei.x<n && nei.y>=0 && nei.y<m){
                if (times[nei.x][nei.y]==-1){
                    times[nei.x][nei.y] = times[cur.x][cur.y] + 1;
                    q.push(nei);
                }
            }
        }
    }
    loop(r,0,t){
        int i,j,k; cin>>i>>j>>k; i--; j--;
        if (times[i][j]==-1){
            cout<<(b[i][j]?'1':'0')<<endl;
            continue;
        }
        k-=times[i][j];
        if (k<=0) cout<<(b[i][j]?'1':'0')<<endl;
        else if (k%2) cout<<(b[i][j]?'0':'1')<<endl;
        else cout<<(b[i][j]?'1':'0')<<endl;
    }
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3 3 3
000
111
000
1 1 1
2 2 2
3 3 3


*/