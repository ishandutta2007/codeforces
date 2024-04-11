#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
int cnt[N];

void solve(){
    int n, c;
    cin >> n >> c;
    int x;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        cnt[x] = 1;
    }
    for(int i = 1; i <= c; i ++ ){
        cnt[i]+=cnt[i-1];
    }
    bool is = true;
    int L,R;
    for(int p = 1; p <= c; p ++ ){
        if(cnt[p]-cnt[p-1] == 0){
            for(int q = 1; q * p <= c; q ++ ){
                if(cnt[q]-cnt[q-1] > 0){

                    L = p * q;
                    R = p * q + q - 1;
                    R = min(R, c);
                    if(cnt[R] - cnt[L-1] > 0){
                        is = false;
                        break;
                    }

                }
            }
        }
        if(is == false) break;
    }
    if(is){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    for(int i = 1; i <= c; i ++ ){
        cnt[i]=0;
    }
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