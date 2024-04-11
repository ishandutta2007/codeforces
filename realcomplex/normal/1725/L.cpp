#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

ll P[N];
ll A[N];

int segt[N * 2];
int n;
void upd(int x, int v){
    x += n;
    while(x > 0){
        segt[x] += v;
        x /= 2;
    }
}

int query(int li, int ri){
    li += n;
    ri += n;
    int cnt = 0;
    while(li <= ri){
        if(li % 2 == 1) cnt += segt[li ++ ];
        if(ri % 2 == 0) cnt += segt[ri -- ]; 
        li /= 2;
        ri /= 2;
    }
    return cnt;
}

int main(){
    fastIO;
    cin >> n;
    vector<ll> pp;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        P[i] = A[i] + P[i - 1];
        pp.push_back(P[i]);
    }
    sort(pp.begin(), pp.end());
    if(pp[0] < 0 || P[n] < pp.back()){
        cout << "-1\n";
        return 0;
    }
    int id;
    int qq = 0;
    ll res = 0;
    for(int i = 1; i <= n; i ++ ){
        id = lower_bound(pp.begin(), pp.end(), P[i]) - pp.begin();
        res += query(id + 1, n - 1);
        upd(id, +1);
    }
    cout << res << "\n";
    return 0;
}