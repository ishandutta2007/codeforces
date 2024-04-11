#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

int ss[N];
vector<int> qq[9];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i <= n; i ++ ){
        ss[i] = s[i - 1] - '0';
        ss[i] += ss[i - 1];
    }
    for(int i = 0 ; i < 9 ; i ++ ) qq[i].clear();
    int w, m;
    cin >> w >> m;
    int cur;
    for(int i = 1; i <= n; i ++ ){
        if(i + w - 1 <= n){
            cur = ss[i + w - 1] - ss[i - 1];
            cur %= 9;
            qq[cur].push_back(i);
        }
    }
    int li, ri, ki;
    int ww;
    pii sp;
    pii cc;
    for(int iq = 1; iq <= m ; iq ++ ){
        cin >> li >> ri >> ki;
        ww = ss[ri] - ss[li - 1];
        ww %= 9;
        sp = mp(-1, -1);
        for(int p = 0 ; p < 9; p ++ ){
            for(int q = 0; q < 9 ; q ++ ){
                if((p * ww + q) % 9 == ki){
                    if(p == q){
                        if(qq[p].size() >= 2){
                            cc = mp(qq[p][0], qq[p][1]);
                            if(sp.fi == -1 || cc < sp){
                                sp = cc;
                            }
                        }
                    }
                    else{
                        if(!qq[p].empty() && !qq[q].empty()){
                            cc = mp(qq[p][0], qq[q][0]);
                            if(sp.fi == -1 || cc < sp){
                                sp = cc;
                            }
                        }
                    }
                }
            }
        }
        cout << sp.fi << " " << sp.se << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}