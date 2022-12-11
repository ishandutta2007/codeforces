#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    double r,d;
    cin >> r >> d;
    int n;
    cin >> n;
    double xi,yi,ri;
    double di;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        cin >> xi >> yi >> ri;
        di = sqrt((xi*xi)+(yi*yi));
        if(di+ri<=r&&(di-ri)>=r-d){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}