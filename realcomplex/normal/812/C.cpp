#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e10

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

const int MAXN = 1e5+5;
ll C[MAXN];

void ini(){
    for(int j = 0;j<MAXN;j++){
        C[j] = INF;
    }
}

ll res(ll k){
    ll T[MAXN];
    T[0] = INF;
    for(int i = 1;i<MAXN;i++) T[i] = C[i]+(i*k);
    sort(T,T+MAXN);
    ll rez = 0;
    for(int j = 0;j<k;j++){
        rez += T[j];
    }
    return rez;
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ini();
    int n;
    ll cot;
    cin >> n >> cot;
    for(int i = 1;i<=n;i++) cin >> C[i];
    int l,r,m;
    l = 0;
    r = MAXN;
    for(int i = 0;i<32;i++){
        m = (l+r)/2;
        ll tek = res(m);
        if(tek<=cot){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout << l << " " << res(l);
    return 0;
}