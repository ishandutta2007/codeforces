#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];

void solve(){
    int n;
    cin >> n;
    int c = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        if(A[i] != 0) c ++ ;
    }
    if(c % 2 != 0){
        cout << "-1\n";
        return;
    }
    vector<pii> vec;
    int id = -1;
    int las = 0;
    for(int i = 1; i <= n; i ++ ){
        if(A[i] != 0){
            if(id == -1) id = i;
            else{
                if(las + 1 < id){
                    vec.push_back(mp(las + 1, id - 1));
                }
                if(vec.empty() && id > 1){
                    vec.push_back(mp(1, id - 1));
                }
                // id un i
                if(A[i] == A[id]){

                    if((i - id - 1) % 2 == 0){
                        vec.push_back(mp(id, i));
                    }
                    else{
                        vec.push_back(mp(id, i - 2));
                        vec.push_back(mp(i-1, i));
                    }
                }
                else{
                    vec.push_back(mp(id, i - 1));
                    vec.push_back(mp(i, i));
                }
                las = i;
                id = -1;
            }
        }
    }
    if(las != n){
        vec.push_back(mp(las + 1, n));
    }
    cout << vec.size() << "\n";
    for(auto i : vec){
        cout << i.fi << " " << i.se << "\n";
    }
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