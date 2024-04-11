#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (1<<17);
int cnt[17];
int ac[17];
int A[N];

void solve(){
    int l, r;
    cin >> l >> r;
    int n = (r - l + 1);
    for(int i = 0 ; i < n; i ++ ){
        cin >> A[i];
    }
    int y;
    for(int i = 0 ; i < 17; i ++ )cnt[i] = ac[i] = 0;
    for(int i = 0 ; i < 17 ; i ++ ){
        for(int j = l ;j <= r; j ++) {
            if((j & (1 << i))){
                cnt[i] ++ ;
            }
            if((A[j - l] & (1 << i))){
                ac[i] ++ ;
            }

        }
    }
    int x = 0;
    for(int i = 0 ; i < 17 ; i ++ ){
        if(cnt[i] != ac[i]){
            x |= (1 << i);
        }
    }
    cout << x << "\n";
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