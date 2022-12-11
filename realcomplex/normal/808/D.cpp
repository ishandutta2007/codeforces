#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    int n;
    cin >> n;
    pair<ll,ll>sk[n];
    ll sum = 0;
    ll el[n];
    for(int i = 0;i<n;i++){
        cin >> el[i];
        sk[i].fi = el[i];
        sk[i].se = i;
        el[i] += sum;
        sum = el[i];
    }
    sort(sk,sk+n);
    ll med = el[n-1];
    if(med%2 == 1){
        cout << "NO";
    }
    else{
        med /= 2;
        ll starp;
        bool c = false;
        ll sa,mid,be;
        for(int i = 0;i<n;i++){
            if(el[i] == med){
                c = true;
            }
            else{
                if(el[i] < med){
                    starp = med - el[i];
                    sa = -1;
                    be = n;
                    for(int x = n;x>0;x/=2){
                        mid = (sa+be) / 2;
                        if(sk[mid].fi == starp && sk[mid].se > i){
                            c = true;
                            break;
                        }
                        else{
                            if(sk[mid].fi <= starp){
                                sa = mid;
                            }
                            else{
                                be = mid;
                            }
                        }
                    }
                }
                else{
                    starp = el[i] - med;
                    sa = -1;
                    be = n;
                    for(int x = n;x>0;x/=2){
                        mid = (sa+be) / 2;
                        if(sk[mid].fi == starp && sk[mid].se < i){
                            c = true;
                            break;
                        }
                        else{
                            if(sk[mid].fi >= starp){
                                be = mid;
                            }
                            else{
                                sa = mid;
                            }
                        }
                    }
                }
            }
        }
        if(c == true){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
	return 0;
}