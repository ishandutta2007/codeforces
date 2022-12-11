#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Tri{
    int ai;
    int bi;
    int ci;
};

vector<Tri> soln;

void solve(vector<int> g){
    int m = g.size();
    for(int i = 0 ; i + 2 < m ; i += 2 ){
        soln.push_back({i, i + 1, i + 2});
    }
    while(m > 4){
        soln.push_back({m-3, m-4, m-5});
        m -= 2;
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    int xr = 0;
    for(int i = 0 ;i  < n; i ++ ){
        cin >> a[i];
        xr ^= a[i];
    }
    if(n % 2 == 0 && xr != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n % 2 == 0){
        a.pop_back();
        solve(a);
    }
    else{
        solve(a);
    }
    cout << soln.size() << "\n";
    for(auto q : soln)
        cout << q.ai + 1 << " " << q.bi + 1 << " " << q.ci + 1 << "\n";
    return 0;
}