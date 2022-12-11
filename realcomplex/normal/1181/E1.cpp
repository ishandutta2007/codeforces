#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 1005;
int a[N], b[N], c[N], d[N];

struct Z{
    pii el;
    int id;
    bool operator< (const Z &T) const {
        return el < T.el;
    }
};

void solve(vector<int> st){
    if(st.size() <= 3)
        return;
    vector<Z> LR;
    for(auto x : st){
        LR.push_back({mp(a[x],+1),x});
        LR.push_back({mp(c[x],-1),x});
    }
    sort(LR.begin(), LR.end());
    int c = 0;
    for(int i = 0; i < (int)LR.size() - 1; i ++ ){
        c += LR[i].el.se;
        if(c == 0){
            vector<int> s1, s2;
            for(int j = 0 ; j <= i ; j ++ )
                if(LR[j].el.se == +1)s1.push_back(LR[j].id);
            for(int j = i + 1; j < LR.size(); j ++ )
                if(LR[j].el.se == +1)s2.push_back(LR[j].id);
            solve(s1);
            solve(s2);
            return;
        }
    }
    vector<Z> UD;
    for(auto x : st){
        UD.push_back({mp(b[x],+1),x});
        UD.push_back({mp(d[x],-1),x});
    }
    sort(UD.begin(), UD.end());
    c = 0;
    for(int i = 0 ; i < (int)UD.size() - 1; i ++ ){
        c += UD[i].el.se;
        if(c == 0){
            vector<int> s1, s2;
            for(int j = 0 ; j <= i ; j ++ )
                if(UD[j].el.se == +1)s1.push_back(UD[j].id);
            for(int j = i + 1; j < UD.size(); j ++ )
                if(UD[j].el.se == +1)s2.push_back(UD[j].id);
            solve(s1);
            solve(s2);
            return;
        }
    }
    cout << "NO\n";
    exit(0);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> chk;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        chk.push_back(i);
    }
    solve(chk);
    cout << "YES\n";
    return 0;
}