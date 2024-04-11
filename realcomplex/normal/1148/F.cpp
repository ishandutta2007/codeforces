#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;
const int LOG = 62;
ll val[N];
ll mask[N];

vector<int> ids[LOG];

int sign(ll x){
    if(x > 0) return +1;
    else if(x == 0) return 0;
    else return -1;
}

int popcount(ll x){
    int cnt = 0;
    for(int i = 0 ;i < LOG; i ++ ){
        if((x & (1ll << i))){
            cnt ++ ;
        }
    }
    return cnt;
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    ll init = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> val[i] >> mask[i];
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if((mask[i] & (1ll << j))){
                ids[j].push_back(i);
                break;
            }
        }
        init += val[i];
    }
    ll msk = 0;
    ll A = 0, B = 0;
    ll fa;
    for(int i = 0 ; i < LOG; i ++ ){
        A=B=0;
        for(auto x : ids[i]){
            if(popcount(mask[x] & (msk | (1ll << i))) % 2 == 0){
                A += val[x];
            }
            else{
                B += val[x];
            }
        }
        fa = A-B;
        if(fa != 0){
            if(sign(init) != sign(fa)){
                msk |= (1ll << i);
            }
        }
    }
    cout << msk << "\n";
    return 0;
}