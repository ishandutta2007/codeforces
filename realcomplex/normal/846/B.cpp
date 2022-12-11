#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    int n,k;
    ll t;
    cin >> n >> k >> t;
    ll r[k];
    ll rt = 0;
    for(int j = 0;j<k;j++){
        cin >> r[j];
        rt += r[j];
    }
    sort(r,r+k);
    ll mx = 0;
    ll c = 0;
    ll l;
    for(int x = 0;x<=n;x++){
        l = t;
        c = 0;
        if(rt*x<=l){
            l-=rt*x;
            c+=(x*k)+x;
            for(int e = 0;e<k;e++){
                for(int j = x+1;j<=n;j++){
                    if(l>=r[e]){
                        l-=r[e];
                        if(e == k-1){
                            c+=2;
                        }
                        else{
                            c++;
                        }
                    }
                }
            }
        }
        mx = max(mx,c);
    }
    cout << mx;
    return 0;
}