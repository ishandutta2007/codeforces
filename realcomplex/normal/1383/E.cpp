#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int N = (int)1e6 + 10;
int dp[N];

int main(){
    fastIO;
    string s;
    cin >> s;
    int n = s.size();
    bool sol = false;
    for(auto x : s){
        if(x == '1')
            sol = true;
    }
    if(!sol){
        cout << n << "\n";
        return 0;
    }
    deque<int> solv;
    for(int i = 0 ; i < s.size(); i ++ ){
        solv.push_back(s[i]-'0');
    }
    int pf = 0;
    while(solv.front() == 0){
        pf ++ ;
        solv.pop_front();
    }
    int sf = 0;
    while(solv.back() == 0){
        sf ++ ;
        solv.pop_back();
    }
    int aa = 0;
    vector<int> seg;
    for(int i = 1; i < solv.size(); i ++ ){
        if(solv[i] == 1){
            seg.push_back(aa);
            aa = 0;
        }
        else{
            aa ++ ;
        }
    }
    int outp = 1;
    int di;
    int nw;
    for(auto x : seg){
        nw = outp;
        for(int j = 0 ; j <= x; j ++ ){
            di = (dp[j] + (outp - dp[j] + MOD) % MOD) % MOD;
            nw = (nw + (di - dp[j] + MOD) % MOD) % MOD;
            dp[j] = di;
        }
        outp = nw;
    }
    outp = (outp * 1ll * (pf + 1)) % MOD;
    outp = (outp * 1ll * (sf + 1)) % MOD;
    cout << outp << "\n";
    return 0;
}