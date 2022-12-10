#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e2 + 10;
char s[maxn][maxn];
int p[maxn];
bool mark[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    reu(i, 1, n){
        reu(j, 1, m)
            cin >> s[i][j];
        s[i][m + 1] = i;
    }
    reu(i, 1, n)
        p[i] = 1;
    int ans = 0;
barc:
    int x = ans;
    rer(i, 1, n){
        while(1){
            if(!mark[p[i]]){
                if(s[i][p[i]] < s[i + 1][p[i]])
                    break;
                else if(s[i][p[i]] == s[i + 1][p[i]])
                    p[i] ++;
                else{
                    mark[p[i]] = true;
                    ans ++;
                    p[i] ++;
                }
            }
            else
                p[i] ++;
        }
    }
    if(ans != x) goto barc;
    cout << ans << endl;
    return 0;
}