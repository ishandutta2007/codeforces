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
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> q;
    for(char x : s)
        q.push_back(x-'a');
    ll cur = 0;
    cur += (1ll << q.back());
    q.pop_back();
    cur -= (1ll << q.back());
    q.pop_back();
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    for(auto x : q)
        cur += (1ll << x);
    ll f;
    for(auto x : q){
        f = (2ll << x);
        if(cur - f >= t){
            cur -= f;
        }
    }
    if(cur == t){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}