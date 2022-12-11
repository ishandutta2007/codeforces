#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int sk[10];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int mx = 1;
    int d = 1;
    while(n>0){
        mx = max(mx,n%10);
        for(int j = 0;j<n%10;j++){
            sk[j]+=d;
        }
        n/=10;
        d*=10;
    }
    cout << mx << "\n";
    for(int x = 0;x<mx;x++){
        cout << sk[x] << " ";
    }
    return 0;
}