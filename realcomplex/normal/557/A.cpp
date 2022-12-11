#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int a1,b1,a2,b2,a3,b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int d1,d2,d3;
    d3 = a3;
    d2 = a2;
    d1 = a1;
    int ans = d3+d2+d1;
    if(ans<n){
        d1 += min(b1-a1,n-ans);
        ans += min(b1-a1,n-ans);
        if(ans<n){
            d2 += min(b2-a2,n-ans);
            ans += min(b2-a2,n-ans);
            if(ans<n){
                d3 += min(b3-a3,n-ans);
                ans += min(b3-a3,n-ans);
            }
        }
    }
    cout << d1 << " " << d2 << " " << d3;
    return 0;
}