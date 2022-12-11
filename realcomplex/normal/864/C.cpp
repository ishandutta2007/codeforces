#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long
#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

signed main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int f,a,b,k;
    cin >> a >> b >> f >> k;
    int c = b;
    int p = 0;
    int ans = 0;
    for(int j = 0;j<k;j++){
        if(p == 0){
            if(c>=a+(a-f) || (c>=a && j == k-1)){
                c -= a;
            }
            else if(c >= f && b >= a-f){
                c = b-(a-f);
                ans++;
            }
            else{
                cout << -1;
                exit(0);
            }
        }
        else{
            if(c>=a+f || (c>=a && j == k-1)){
                c-=a;
            }
            else if(c>=(a-f) && b >= f){
                c = b-f;
                ans++;
            }
            else{
                cout << -1;
                exit(0);
            }
        }
        p = 1-p;
    }
    cout << ans;
    return 0;
}