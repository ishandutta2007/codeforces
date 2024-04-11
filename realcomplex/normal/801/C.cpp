#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXN = 1e5+5;
ld cur[MAXN],req[MAXN];

void ini(){
    for(int j = 0;j<MAXN;j++){
        cur[j] = 1e12;
        req[j] = 0.0;
    }
}

ld p;
int n;
bool can(ld k){
    ld r = 0;
    for(int j = 0;j<MAXN;j++){
        r += max(ld(0.0),(req[j]*k)-cur[j]);
    }
    ld sup = p*k;
    if(sup>=r) return true;
    else return false;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    ini();
    cin >> n >> p;
    ld s = 0;
    for(int j = 0;j<n;j++){
        cin >> req[j] >> cur[j];
        s+=req[j];
    }
    if(s<=p){
        cout << -1;
        exit(0);
    }
    ld l = 0,r = 1e10;
    for(int operations = 0;operations<75;operations++){
        ld m = (l+r)/2;
        if(can(m)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}