#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

void winner(int x){
    if(x == 0)
        cout << "sjfnb\n";
    else
        cout << "cslnb\n";
    exit(0);
}

int main(){
    int n;
    cin >> n;
    vector<ll> cnt;
    ll a;
    ll tot = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a;
        cnt.push_back(a);
    }
    sort(cnt.begin(), cnt.end());
    int eq = 0;
    int pos = -1;
    for(int i = 1; i < cnt.size(); i ++ ){
        if(cnt[i] == cnt[i - 1]){
            eq ++ ;
            if(i > 1){
                if(cnt[i - 2] == cnt[i - 1] - 1){
                    winner(1);
                }
            }
            if(cnt[i] == 0) winner(1);
            pos = i - 1;
        }
    }
    if(eq > 1)
        winner(1);
    ll total = 0;
    if(pos != -1)
        cnt[pos] -- , total ++ ;
    for(int i = 0 ; i < cnt.size(); i ++ ){
        total += cnt[i] - i;
        total %= 2;
    }
    winner(!total);
    return 0;
}