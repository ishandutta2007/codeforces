#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    int cnt;
    for(int j = 0;j<n;j++){
        cnt = 1;
        for(int x = 0;x<n;x++){
            if(sk[j] < sk[x]){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
    return 0;
}