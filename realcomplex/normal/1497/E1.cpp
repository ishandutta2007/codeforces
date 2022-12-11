#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int M = (int)1e7 + 10;
int red[M];

map<int, int> pos;

void solve(){
    int n, k;
    cin >> n >> k;
    int las = 0;
    pos.clear();
    int a;
    int sol = 1;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        a = red[a];
        if(pos.count(a) && pos[a] > las){
            las = i-1;
            sol ++ ;
        }
        pos[a] = i;
    }
    cout << sol << "\n";
}

int main(){
    fastIO;
    for(int i = 1; i < M ;i ++ ){
        red[i]=i;
    }
    for(int i = 2; i * i < M; i ++ ){
        if(red[i] == i){
            for(int j = 2 * i; j < M; j += i){
                while(red[j] % (i * i) == 0){
                    red[j] /= (i * i);
                }
            }
        }
    }
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        solve();
    }
    return 0;
}