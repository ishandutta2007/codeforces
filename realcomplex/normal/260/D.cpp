#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

vector<pii> col[2];

int main(){
    fastIO;
    int n;
    cin >> n;
    int c, w;
    for(int i = 1; i <= n ; i ++ ){
        cin >> c >> w;
        col[c].push_back(mp(w, i));
    }
    for(int t = 0 ;t < 2 ; t ++ )
        sort(col[t].begin(), col[t].end());

    int i = 0, j = 0;
    int v;
    while(i < col[0].size() && j < col[1].size()){
        v = min(col[0][i].fi, col[1][j].fi);
        cout << col[0][i].se << " " << col[1][j].se << " " << v << "\n";
        col[0][i].fi -= v;
        col[1][j].fi -= v;
        if(col[0][i].fi == 0 && i + 1 < col[0].size())
            i ++ ;
        else
            j ++ ;
    }
    return 0;
}