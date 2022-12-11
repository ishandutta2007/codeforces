#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair

int n, m;

ld find_x(bool rev){
    vector<pdd> poly;
    poly.push_back(mp(0.0, -1.0));
    for(int i = 0 ; i < n; i ++ ){
        poly.push_back(mp(i, 0.0));
        poly.push_back(mp(i, m));
    }
    poly.push_back(mp(n, 0));
    poly.push_back(mp(n, -1.0));
    cout << "? " << poly.size() << endl;
    for(auto x : poly){
        if(!rev)
            cout << x.fi << " " << x.se << endl;
        else{
            cout << x.se << " " << x.fi << endl;
        }
    }
    cout << endl;
    ld q;
    cin >> q;
    ld mm = (ld)m * (ld)m;
    ld S = (ld)m / 2.0;
    ld x = q * mm / S + 1.0;
    x /= 2.0;
    return m - x;
}

int main(){
    cin >> n >> m;
    n=m=100;
    ld xx = find_x(true);
    ld yy = find_x(false);
    cout << fixed << setprecision(6) << "! " << xx << " " << yy << endl;
    return 0;
}