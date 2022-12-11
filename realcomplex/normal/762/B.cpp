#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    vector<ll>usb,ps;
    int m;
    cin >> m;
    ll co;
    string typ;
    for(int i = 0;i<m;i++){
        cin >> co >> typ;
        if(typ == "USB"){
            usb.push_back(co);
        }
        else{
            ps.push_back(co);
        }
    }
    sort(usb.begin(),usb.end());
    sort(ps.begin(),ps.end());
    reverse(usb.begin(),usb.end());
    reverse(ps.begin(),ps.end());
    ll total = 0;
    int eq = 0;

    for(int i = 0;i<a && usb.size() > 0;i++){
        total += usb[usb.size()-1];
        usb.erase(usb.begin() + (usb.size() - 1));
        eq++;
    }
    for(int i = 0;i<b && ps.size() > 0;i++){
        total += ps[ps.size()-1];
        ps.erase(ps.begin() + (ps.size() - 1));
        eq++;
    }

    while((ps.size() > 0 || usb.size() > 0) && c > 0){
        if(ps.size() > 0 && usb.size() > 0){
            if(ps[ps.size()-1] < usb[usb.size()-1]){
                total += ps[ps.size()-1];
                ps.erase(ps.begin() + (ps.size() - 1));
            }
            else{
                total += usb[usb.size()-1];
                usb.erase(usb.begin() + (usb.size() - 1));
            }
        }
        else if(ps.size() > 0){
            total += ps[ps.size() - 1];
            ps.erase(ps.begin() + (ps.size() - 1));
        }
        else{
            total += usb[usb.size() - 1];
            usb.erase(usb.begin() + (usb.size() - 1));
        }
        eq++;
        c--;
    }
    cout << eq << " " << total;
    return 0;
}