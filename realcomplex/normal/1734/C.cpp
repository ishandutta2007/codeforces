#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
vector<int> T[N];
bool ban[N];

void solve(){
    int n;
    cin >> n;
    char x;
    ll sol = 0;
    for(int i = 1; i <= n; i ++ ){
        ban[i]=false;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        if(x == '1'){
            for(auto y : T[i]){
                ban[y]=true;
            }
        }
        else{
            for(auto y : T[i]){
                if(!ban[y]){
                    sol+=y;
                    break;
                }
            }
        }
    }
    cout << sol << "\n";
}

int main(){
    fastIO;
    for(int i = 1 ; i < N; i ++ ){
        for(int j = i ; j < N; j += i){
            T[j].push_back(i);
        }
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}