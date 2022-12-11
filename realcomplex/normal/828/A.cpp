#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    int n,a,b;
    cin >> n >> a >> b;
    int singles = 0;
    int sk;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk == 1){
            if(a > 0){
                a--;
            }
            else if(b > 0){
                b--;
                singles++;
            }
            else if(singles > 0){
                singles--;
            }
            else{
                ans++;
            }
        }
        else{
            if(b > 0){
                b--;
            }
            else{
                ans+=2;
            }
        }
    }
    cout << ans;
    return 0;
}