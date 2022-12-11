#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
multiset<int> opr[N];


int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        opr[a].insert(0);
    }
    int res = (int)1e9;
    int cur;
    for(int i = N - 1; i >= 1; i -- ){
        if(opr[i].size() >= k){
            cur = 0;
            auto it = opr[i].begin();
            for(int j = 0 ; j < k ; j ++ ){
                cur += *it;
                it ++ ;
            }
            res = min(res, cur);
        }
        if(i > 1)
            for(auto x : opr[i]){
                opr[i/2].insert(x + 1);
            }
        opr[i].clear();
    }
    cout << res;
    return 0;
}