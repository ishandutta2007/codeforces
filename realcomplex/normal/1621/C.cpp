#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e4 + 1;
int mark[N];
int P[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) mark[i]=0;
    for(int i = 1; i <= n; i ++ ){
        if(mark[i] == 0){
            vector<int> ord;
            int r;
            while(1){
                cout << "? " << i << endl;
                cin >> r;
                mark[r]++;
                if(mark[r] > 1){
                    break;
                }
                ord.push_back(r);
            }
            int id = -1;
            for(int j = 0 ;j < ord.size(); j ++ ){
                if(ord[j] == i) id = j;
            }
            for(int t = 0; t < ord.size(); t ++ ){
                P[ord[t]] = ord[(t + 1) % ord.size()];
            }
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i ++ ){
        cout << P[i] << " ";
    }
    cout << endl;
}

int main(){
    //fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}