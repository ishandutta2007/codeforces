#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int st[N];
int seq[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int t, l, r;
    vector<pii> bad;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> t >> l >> r;
        if(t == 1){
            for(int j = l ; j < r; j ++ )
                st[j] = 1;
        }
        else{
            bad.push_back(mp(l,r));
        }
    }
    bool ok;
    for(auto p : bad){
        ok = false;
        for(int j = p.fi ; j < p.se; j ++ ){
            if(st[j] != 1){
                ok = true;
                st[j] = 2;
                break;
            }
        }
        if(!ok){
            cout << "NO\n";
            return 0;
        }
    }
    seq[1] = N;
    for(int i = 2; i <= n; i ++ ){
        if(st[i - 1] <= 1)
            seq[i] = seq[i - 1] + 1;
        else{
            seq[i] = seq[i - 1] - 1;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ )
        cout << seq[i] << " ";
    return 0;   
}