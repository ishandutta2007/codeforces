#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=998244353;
// head

void solve() {
    int n,m;
    cin >> n >> m;

    vector<string> s(n+1);
    rep(i, 0, n) cin >> s[i];

    vector ok(n,vector<bool>(m));
    vector<int> dx={0,-1,0,1};
    vector<int> dy={1,0,-1,0};

    rep(i,0,n) rep(j,0,m) {
        ok[i][j]=true;
        rep(d,0,4) {
            int nx=i+dx[d],ny=j+dy[d];
            if (min(nx,ny)<0||nx>=n||ny>=m) continue;
            if (s[nx][ny]=='#') ok[i][j]=false;
        }  
    }   
    
    vector frm(n,vector<PII>(m,{-1,-1}));
    struct node {
        int x,y;
        int cnt;
    };
    deque<node> dq;

    auto print_ans=[&](int x,int y) {
        cout << "YES" << endl;
        //bug(frm[0][3].fi),debug(frm[0][3].se);

        while (true) {
            s[x][y]='#';
            auto [u,v]=frm[x][y];
           if (mp(u,v)==mp(x,y)) break;
           else x=u,y=v;
        }

        rep(i,0,n) cout << s[i] << endl;
        return;
    };

    rep(i,0,n) if (ok[i][0]) {
        frm[i][0]={i,0};
        if (s[i][0]=='#') dq.push_front({i,0,0});
        else dq.push_back({i,0,1});
    }
    while (!dq.empty()) {
        auto [x,y,cnt]=dq.front();
        dq.pop_front();

        if (y==m-1) {
            print_ans(x,y);
            return;
        }

        for (auto dx:{-1,1}) for (auto dy:{-1,1}) {
            int nx=x+dx,ny=y+dy;
            if (nx<0||nx>=n||ny<0||ny>=m) continue;

            if (frm[nx][ny]==mp(-1,-1) && ok[nx][ny]) {
                frm[nx][ny]={x,y};
               // bug(nx),bug(ny),bug(x),debug(y);
                if (s[nx][ny]=='#') dq.push_front({nx,ny,cnt});
                else dq.push_back({nx,ny,cnt+1});
            }
        }
    }
    cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    cout << fixed << setprecision(6);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}