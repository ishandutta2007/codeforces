#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int query(vector<int> s1, vector<int> s2){
    cout << s1.size() << " " << s2.size() << " ";
    for(auto x : s1)
        cout << x << " ";
    for(auto x : s2)
        cout << x << " ";
    cout << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> ff;
    vector<int> ss;
    ff.push_back(1);
    for(int i = 2; i <= n; i ++ ){
        ss.push_back(i);
    }
    int cur = query(ff,ss);
    int L = 2, R = n;
    int M;
    while(L < R){
        M = (L + R) / 2;
        ss.clear();
        for(int i = 2; i <= M ; i ++ ){
            ss.push_back(i);
        }
        if(query(ff, ss) >= cur)
            R = M;
        else
            L = M + 1;
    }
    ff.clear();
    ss.clear();
    ff.push_back(L);
    for(int i = 1; i <= n; i ++ ){
        if(i != L)
            ss.push_back(i);
    }
    int answ = query(ff, ss);
    cout << -1 << " " << answ << endl;
    fflush(stdout);
}

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases -- )
        solve();
    return 0;
}