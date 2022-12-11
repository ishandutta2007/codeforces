#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define t abs

int k[1005];

int main(){

    int n;
    cin >> n;
    int sk;
    int mx = 0;
    int am = 0;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(k[sk]==0){
            am++;
        }
        k[sk]++;
        mx = max(mx,k[sk]);
    }
    cout << mx << " " << am;
    return 0;
}