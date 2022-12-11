#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
vector<int> use = {11, 111, 1111, 11111, 111111};
bool can[N];

int main(){
    fastIO;
    can[0] = true;
    for(int i = 0 ; i < N; i ++ ){
        if(can[i]){
            for(auto x : use){
                if(i + x < N)
                    can[i + x] = true;
            }
        }
    }
    int q;
    cin >> q;
    for(int iq = 1; iq <= q; iq ++ ){
        int n;
        cin >> n;
        if(n >= N){
            cout << "YES\n";
        }
        else{
            if(can[n])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}