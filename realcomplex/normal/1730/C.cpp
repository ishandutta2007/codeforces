#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> pos[10];
int p[10];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < 10 ; i ++ ){
        pos[i].clear();
        p[i] = 0;
    }
    for(int i = 0 ; i < n; i ++ ){
        pos[s[i] - '0'].push_back(i);
    }
    int go = -1;
    vector<int> soln;
    vector<int> ex;
    for(int i = 0 ; i < n; i ++ ){
        if(i > go){
            for(int d = 0; d < 10; d ++ ){
                while(p[d] < pos[d].size() && pos[d][p[d]] < i){
                    p[d] ++ ;
                }
                if(p[d] < pos[d].size()){
                    go = pos[d][p[d]];
                    soln.push_back(d);
                    break;
                }
            }
        }
        if(i < go){
            ex.push_back(s[i] - '0');
        }
    }
    sort(ex.begin(), ex.end());
    int iq = 0;
    for(auto p : soln){
        while(iq < ex.size() && ex[iq] + 1 <= p){
            cout << min(ex[iq] + 1, 9);
            iq++;
        }
        cout << p;
    }
    while(iq < ex.size()){
        cout << min(ex[iq] + 1, 9);
        iq ++ ;
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt ++ ){
        solve();
    }
    return 0;
}