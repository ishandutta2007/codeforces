#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll rcomb(ll x){
    ll l=1, r=1e9;
    while(l+1<r){
        ll mid = (l+r)/2;
        if(mid*(mid-1)/2 <= x){
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void chk(bool x){
    if(!x){
        cout << "Impossible\n";
        exit(0);
    }
}

int cnt[2000010];

int main()
{
    ll zz, zo, oz, oo;
    if(0){
        string x;
        cin >> x;
        int n = x.length();
        zz=zo=oz=oo=0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(x[i] == '0' && x[j] == '0') ++zz;
                if(x[i] == '0' && x[j] == '1') ++zo;
                if(x[i] == '1' && x[j] == '0') ++oz;
                if(x[i] == '1' && x[j] == '1') ++oo;
            }
        }
    } else {
        cin >> zz >> zo >> oz >> oo;
    }
    ll zc = rcomb(zz);
    ll oc = rcomb(oo);
    if(zz == 0 && zo == 0 && oz == 0 && oo == 0){
        cout << "0\n";
        return 0;
    }
    if(zz == 0 && zo == 0 && oz == 0){
        chk(oo);
        chk(oc*(oc-1)/2 == oo);
        cout << string(oc, '1');
        return 0;
    }
    if(zo == 0 && oz == 0 && oo == 0){
        chk(zz);
        chk(zc*(zc-1)/2 == zz);
        cout << string(zc, '0');
        return 0;
    }
    
    chk(zc*(zc-1)/2 == zz);
    chk(oc*(oc-1)/2 == oo);

    ll n = zc+oc;
    chk(zz + zo + oz + oo == n*(n-1)/2);

    ll czo = zo;
    int czc = zc;
    for(int i=oc; 1<=i; --i){
        czc -= czo / i;
        cnt[i] = czo / i;
        czo %= i;
    }
    cnt[0] = czc;
    
    for(int i=oc; 1<=i; --i){
        cout << string(cnt[i], '0');
        cout << '1';
    }
    cout << string(cnt[0], '0');
    cout << endl;
    return 0;
}