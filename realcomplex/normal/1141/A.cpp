#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    int n, m;
    cin >> n >> m;
    if(m % n != 0){
        cout << -1;
        return 0;
    }
    int d = m / n, answ = 0;
    while(d % 2 == 0) d /= 2, answ ++ ;
    while(d % 3 == 0) d /= 3, answ ++ ;
    if(d != 1){
        cout << -1;
        exit(0);
    }
    cout << answ << "\n";
    return 0;
}