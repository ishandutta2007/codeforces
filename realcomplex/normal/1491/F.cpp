#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int ask(vector<int> a, vector<int> b){
    cout << "? " << a.size() << " " << b.size() << endl;
    for(auto x : a) cout << x << " ";
    cout << endl;
    for(auto x : b) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> ai, bi;
    ai = {1};
    int val;
    int li;
    int ri;
    int mid;
    for(int i = 2; i <= n; i ++ ){
        val = ask(ai, {i});
        if(val != 0){
            li = 1;
            ri = i - 1;
            while(li < ri){
                mid = (li + ri) / 2;
                ai.clear();
                for(int i = 1; i <= mid; i ++ )
                    ai.push_back(i);
                if(ask(ai, {i}) == 0){
                    li = mid + 1;
                }
                else{
                    ri = mid;
                }
            }
            vector<int> sol;
            for(int j = 1; j < li; j ++ ) sol.push_back(j);
            for(int j = li + 1; j < i; j ++ ) sol.push_back(j);
            for(int j = i + 1; j <= n; j ++ ){
                if(ask({i}, {j}) == 0) sol.push_back(j);
            }
            cout << "! " << sol.size() << " ";
            for(auto x : sol) cout << x << " ";
            cout << endl;
            return;
        }
        ai.push_back(i);
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        solve();
    }
    return 0;
}