#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    ll sk;
    ll op = 0;
    ll ad = 0;
    for(int j = 0;j<n;j++){
        cin >> sk;
        if(ad>sk){
            op += ad-sk;
            ad -= ad-sk;
        }
        else{
            op += sk-ad;
            ad += sk-ad;
        }
    }
    cout << op;
    return 0;
}