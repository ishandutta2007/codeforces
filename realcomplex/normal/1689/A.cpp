#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> aa(n), bb(m);
    for(int i = 0 ; i < n; i ++ ) cin >> aa[i];
    for(int i = 0 ; i < m; i ++ ) cin >> bb[i];
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    int p = 0, q = 0;
    int las = -1;
    int ord = 0;
    while(p < aa.size() && q < bb.size()){
        if(aa[p] < bb[q]){
            if(las == 0 && ord == k){
                las = 1;
                ord = 1;
                cout << bb[q];
                q ++ ;
            }
            else{
                if(las == 0) ord ++ ;
                else ord = 1;
                cout << aa[p];
                p ++ ;
                las = 0;
            }
        }
        else{
            if(las == 1 && ord == k){
                las = 0;
                ord = 1;
                cout << aa[p];
                p ++ ;
            }
            else{
                if(las == 1) ord ++ ;
                else ord = 1;
                cout << bb[q];
                q ++ ;
                las = 1;
            }

        }
    }
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}