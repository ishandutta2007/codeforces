#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        int p1 = n - k1;
        int p2 = n - k2;
        if(k1 > k2) swap(k1,k2);
        if(p1 > p2) swap(p1,p2);
        while(k2 - 2 >= k1){
            w -- ;
            k2 -= 2;
        }
        w -= k1;
        while(p2 - 2 >= p1){
            b -- ;
            p2 -= 2;
        }
        b -= p1;
        if(w <= 0 && b <= 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}