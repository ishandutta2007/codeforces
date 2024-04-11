#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
int low[N];

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        a[i]=low[a[i]];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int one = 0;
    int init = 0;
    for(int i = 0 ; i < n; i ++ ){
        cnt ++ ;
        if(i + 1 == n || a[i] != a[i + 1]){
            if(a[i] == 1 || cnt % 2 == 0){
                one += cnt;
            }
            init = max(init,cnt);
            cnt = 0;
        }
    }
    ll w;
    int q;
    cin >> q;
    for(int t = 0; t < q; t ++ ){
        cin >> w;
        if(w == 0){
            cout << init << "\n";
        }
        else{
            cout << max(init,one) << "\n";
        }
    }
}

int main(){
    fastIO;
    for(int i = 1; i < N ; i ++ ){
        low[i]=i;
    }
    for(int p = 2; p * p < N ; p ++ ){
        for(int j = p * p ; j < N ; j += p * p){
            while(low[j]%(p*p)==0)low[j]/=(p*p);
        }
    }
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc ; t ++ ){
        solve();
    }
    return 0;
}