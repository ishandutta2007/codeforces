#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 18;
const int N = (int)2e5 + 10;
int b[N];

void solve(){
    int n;
    cin >> n;
    int m = n * 2;
    char f;
    int c1 = 0;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> f;
        b[i] = f - '0';
        c1 += b[i];
    }
    if(c1 % 2 != 0){
        cout << "-1\n";
        return;
    }
    int odd = 0;
    vector<int> pap, cq;
    for(int i = 0 ; i < m ; i += 2 ){
        if(b[i] != b[i + 1]){
            if(b[i] == odd){
                pap.push_back(i);
            }
            else{
                pap.push_back(i + 1);
            }
            odd ^= 1;
        }
        cq.push_back(i);
    }
    int k = pap.size();
    cout << k << " ";
    for(auto i : pap) cout << i + 1 << " ";
    cout << "\n";
    for(auto x : cq) cout << x + 1 << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}