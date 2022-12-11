#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int vl[N];

void solve(){
    string s;
    int x;
    cin >> s >> x;
    int n = s.size();
    for(int i = 0 ; i < n; i ++ )
        vl[i] = -1;
    int p, q;
    for(int i = 0 ;i < n; i ++ ){
        if(s[i] == '0'){
            p = i - x;
            q = i + x;
            if(p >= 0){
                if(vl[p] == -1){
                    vl[p] = 0;
                }
                else if(vl[p] == 1){
                    cout << "-1\n";
                    return;
                }
            }
            if(q < n){
                if(vl[q] == -1){
                    vl[q] = 0;
                }
                else if(vl[q] == 1){
                    cout << "-1\n";
                    return;
                }
            }
        }
        else{
            p = i - x;
            q = i + x;
            if(p < 0 && q >= n){
                cout << "-1\n";
                return;
            }
            if(p < 0){
                if(vl[q] == -1){
                    vl[q] = 1;
                }
                else if(vl[q] == 0){
                    cout << "-1\n";
                    return ;
                }
            }
            else if(q >= n){
                if(vl[p] == -1){
                    vl[p] = 1;
                }
                else if(vl[p] == 0){
                    cout << "-1\n";
                    return ;
                }
            }
            else{
                if(vl[p] == -1){
                    vl[p] = 1;
                }
                else if(vl[p] == 0){
                    if(vl[q] == 0){
                        cout << "-1\n";
                        return;
                    }
                    vl[q] = 1;
                }
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        if(vl[i] == -1) vl[i] = 0;
        cout << vl[i];
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}