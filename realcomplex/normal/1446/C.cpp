#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

int solve(vector<int> aa, int lg){
    if(aa.size() <= 2) return 0;
    vector<int> b, f;
    for(auto x : aa){
        if((x & (1 << lg))){
            b.push_back(x);
        }
        else{
            f.push_back(x);
        }
    }
    if(b.empty()) return solve(f, lg - 1);
    if(f.empty()) return solve(b, lg - 1);
    int bi = b.size();
    int fi = f.size();
    int ret = min(solve(b,lg-1)+fi-1,solve(f,lg-1)+bi-1);
    return ret;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a[i];
    }
    cout << solve(a, 30);
    return 0;
}