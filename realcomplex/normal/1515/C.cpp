#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m, x;
        cin >> n >> m >> x;
        int H;
        priority_queue<pii,vector<pii>,greater<pii>> lis;
        for(int i = 1; i <= m ; i ++ ){
            lis.push(mp(0, i));
        }
        int cur;
        int id;
        cout << "YES\n";
        for(int i = 1; i <= n; i ++ ){
            cin >> H;
            cur = lis.top().fi;
            id = lis.top().se;
            lis.pop();
            lis.push(mp(cur + H, id));
            cout << id << " ";
        }
        cout << "\n";
    }
    return 0;
}