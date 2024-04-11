#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    string t;
    cin >> t;
    int soln = 0;
    bool flip;
    for(int j = 0 ; j < t.size(); j ++ ){
        flip = false;
        if(j > 0 && t[j] == t[j - 1]) flip = true;
        if(j > 1 && t[j] == t[j - 2]) flip = true;
        if(!flip) continue;
        soln ++ ;
        set<char> ff;
        for(int i = -2; i <= 2; i ++ ){
            if(i == 0) continue;
            if(j + i >= 0 && j + i < t.size()){
                ff.insert(t[j + i]);
            }
        }
        for(char q = 'a'; q <= 'z'; q ++ ){
            if(ff.count(q)) continue;
            t[j]=q;
            break;
        }
    }
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc;  t ++ ){
        solve();
    }
    return 0;
}