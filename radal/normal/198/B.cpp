#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
string r,l;
int n,k;
bool visited[N][2];
string bfs(){
    visited[1][0] = 1;
    queue <pair<pll,int> > q;
    q.push({{1,0},0});
    while (!q.empty()){
        auto p = q.front();
        if (p.X.X+k > n) return "YES";
        q.pop();
        int dist = p.Y;
        if (p.X.X < n && !visited[p.X.X+1][p.X.Y]){
            if (p.X.Y){
                if (r[p.X.X+1] == '-'){
                    q.push({{p.X.X+1,1},dist+1});
                    visited[p.X.X+1][1] = 1;
                }
            }
            else{
                if (l[p.X.X+1] == '-'){
                    q.push({{p.X.X+1,0},dist+1});
                    visited[p.X.X+1][0] = 1;
                }
            } 
        }
        if (p.X.X && !visited[p.X.X-1][p.X.Y] && p.X.X-1 > dist+1){
            visited[p.X.X-1][p.X.Y] = 1;
            if (p.X.Y && r[p.X.X-1] == '-') q.push({{p.X.X-1,p.X.Y},dist+1});
            if (!p.X.Y && l[p.X.X-1] == '-') q.push({{p.X.X-1,p.X.Y},dist+1});
        }
        if (!visited[p.X.X+k][1-p.X.Y]){
            visited[p.X.X+k][1-p.X.Y] = 1;
            if (!p.X.Y && r[p.X.X+k] == '-') q.push({{p.X.X+k,1-p.X.Y},dist+1});
            if (p.X.Y && l[p.X.X+k] == '-') q.push({{p.X.X+k,1-p.X.Y},dist+1});
        }
    }
    return "NO";
}
int main(){
    cin >> n >> k;
    cin >> l >> r;
    if (n <= k){
        cout << "YES";
        return 0;
    }
    l='X'+l;
    r='X'+r;
    cout << bfs();
    return 0;
}