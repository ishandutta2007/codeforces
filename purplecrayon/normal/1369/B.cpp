#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    int n; string s;
    cin >> n >> s;
    deque<char> lft; lft.push_back(s[n-1]);
    for (int i = n-2; i >= 0; i--){
        while (s[i] == '1' && lft.size() >= 2 && lft.front() == '0' && lft[0] == lft[1]) lft.pop_front();
        if (s[i] == '1' && lft.front() == '0'){
        } else lft.push_front(s[i]);
    }
    string ss="";
    for (auto c : lft) ss+=c;
    cout << ss << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}