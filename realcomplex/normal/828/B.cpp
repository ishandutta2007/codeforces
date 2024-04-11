#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n,m;
    cin >> n >> m;
    char cur[n+1][m+1];
    int lx = 109,ly = 109,rx = 0,ry = 0;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++){
            cin >> cur[i][j];
            if(cur[i][j]=='B')
                lx=min(lx,i),rx=max(rx,i),ly=min(ly,j),ry=max(ry,j);
        }
    if(lx==109){//corner case - all colors are white
        cout << 1 << "\n";
        return 0;
    }
    int ls = rx-lx+1;
    int rs = ry-ly+1;
    int ans = 0;
    for(int i = lx;i<=rx;i++)
        for(int j = ly;j<=ry;j++)
            if(cur[i][j]=='W')
                ans++;
    if(ls==rs){
        cout << ans << "\n";
        return 0;
    }
    if(rs>ls){
        if(rs<=n)
            cout << ans + (rs-ls)*rs << "\n";
        else
            cout << -1 <<"\n";
        return 0;
    }
    if(ls<=m)
        cout << ans + (ls-rs) * ls;
    else
        cout << -1 << "\n";
    return 0;
}