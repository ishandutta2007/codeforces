#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)t; (i)++)
#define reu(i, s, e) for(ll (i) = (ll)s; (i) <= (ll)e; (i)++)
#define rer(i, s, e) for(ll (i) = (ll)s; (i) < (ll)e; (i)++)
#define mset(arr, val) memset(arr, val, sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 5e2 + 100;
char a[maxn][maxn];
bool mark[maxn][maxn];
int q;

void dfs(int x, int y){
    mark[x][y] = true;
    if(a[x][y + 1] == '.' && !mark[x][y + 1])
        dfs(x, y + 1);
    if(a[x][y - 1] == '.' && !mark[x][y - 1])
        dfs(x, y - 1);
    if(a[x + 1][y] == '.' && !mark[x + 1][y])
        dfs(x + 1, y);
    if(a[x - 1][y] == '.' && !mark[x - 1][y])
        dfs(x - 1, y);
    if(q){
        a[x][y] = 'X';
        q--;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m >> q;
    int x, y;
    reu(i, 1, n){
        reu(j, 1, m){
            cin >> a[i][j];
            if(a[i][j] == '.'){
                x = i;
                y = j;
            }
        }
    }

    reu(i, 1, n){
        mark[i][0] = true;
        mark[i][m + 1] = true;
    }
    reu(j, 1, m){
        mark[0][j] = true;
        mark[n + 1][j] = true;
    }
    dfs(x, y);

    reu(i, 1, n){
        reu(j, 1, m)
            cout << a[i][j];
        cout << endl;
    }
	return 0;
}