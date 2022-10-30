#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=3e3+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
int n,k,cnt;
int dist[N][N];
int suf[N],p[N];
void bfs(){
    queue<pll> q;
    q.push({0,1});
    dist[0][1] = 1; 
    while (!q.empty()){
        pll a = q.front();
        //debug(a.Y);
        q.pop();
        if (dist[a.X][a.Y] == k+1) continue;
        if (p[a.X]){
            if (a.Y+1 <= n && suf[a.Y] < 100 && !dist[a.X][a.Y+1]){
                dist[a.X][a.Y+1] = dist[a.X][a.Y]+1;
                q.push({a.X,a.Y+1});
                cnt++;
            }
            if (a.Y+1 <= n && suf[a.Y] && !dist[a.Y+1][a.Y+2]){
                dist[a.Y+1][a.Y+2] = dist[a.X][a.Y]+1;
                q.push({a.Y+1,a.Y+2});
                cnt++;
            }
            if (p[a.X] != 100 && suf[a.Y] && a.Y < n && !dist[a.Y][a.Y+1]){
                dist[a.Y][a.Y+1] = dist[a.X][a.Y]+1;
                q.push({a.Y,a.Y+1});
                cnt++;
            }
        }
        else{
            if (a.Y <= n && suf[a.Y] && !dist[a.Y][a.Y+1]){
                dist[a.Y][a.Y+1] = dist[a.X][a.Y]+1;
                q.push({a.Y,a.Y+1});
                cnt++;
            }
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    cin >> n >> k;
    rep(i,0,n) cin >> p[i];
    suf[n-1] = p[n-1];
    repr(i,n-2,0)
        suf[i] = max(p[i],suf[i+1]);
    bfs();
    cout << cnt+1 << endl;
    debug(dist[1][2]);
    return 0;
}