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
const long long int N=7e1+30,mod = 1e9+7,inf=2e5;
const long double eps = 0.0001;
string s[N];
int dist[N][N][N],n;
pair<pll,int> p[N][N][N];
void bfs(int x,int y,int z){
    dist[x][y][z] = 1;
    queue <pair<pll,int> > q;
    q.push({{x,y},z});
    p[x][y][z] = {{-1,-1},-1};
    while (!q.empty()){
        auto v = q.front();
        int a = v.X.X,b = v.X.Y,c = v.Y;
        q.pop();
        rep(i,0,n){
            if (i != b && i != c && !dist[i][b][c] && s[a][i] == s[b][c]){
                dist[i][b][c] = dist[a][b][c]+1;
                p[i][b][c] = {{a,b},c};
                q.push({{i,b},c});
            }
            if (i != a && i != c && !dist[a][i][c] && s[a][c] == s[b][i]){
                dist[a][i][c] = dist[a][b][c]+1;
                q.push({{a,i},c});
                p[a][i][c] = {{a,b},c};
            }
            if (i != b && i != a && !dist[a][b][i] && s[c][i] == s[b][a]){
                dist[a][b][i] = dist[a][b][c]+1;
                q.push({{a,b},i});
                p[a][b][i] = {{a,b},c};
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int b,a,c;
    cin >> n >> a >> b >> c;
    a--;
    b--;
    c--;
    rep(i,0,n) cin >> s[i];
    bfs(a,b,c);
    if (max(dist[0][1][2],max(dist[0][2][1],max(dist[1][0][2],max(dist[1][2][0],max(dist[2][0][1],dist[2][1][0]))))) == 0){
        cout << -1;
        return 0;
    }
    int i,j,k,mi = 1e8;
    rep(x,0,3){
        rep(y,0,3){
            rep(z,0,3){
                if (x != y && y != z && z != x && dist[x][y][z] < mi && dist[x][y][z]){
                    mi = dist[x][y][z];
                    i = x;
                    j = y;
                    k = z;
                }
            }
        }
    }
    cout << mi-1 << endl;
    stack <pll> st;
    while(p[i][j][k].X.X != -1){
        if (p[i][j][k].X.X != i){
            st.push({p[i][j][k].X.X,i});
            i = p[i][j][k].X.X;
        }
        else{
            if (p[i][j][k].X.Y != j){
                st.push({p[i][j][k].X.Y,j});
                j = p[i][j][k].X.Y;
            }
            else{
                st.push({p[i][j][k].Y,k});
                k = p[i][j][k].Y;
            }
        }
    }
    while (!st.empty()){
        cout << st.top().X+1 << ' ' << st.top().Y+1 << endl;
        st.pop();
    }
    return 0;
}