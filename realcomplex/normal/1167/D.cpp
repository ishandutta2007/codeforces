#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int bl = 0;
    char z;
    for(int i = 1; i <= n; i ++ ){
        cin >> z;
        if(z == '(') bl ++ ;
        else bl -- ;
        if(z == '(') cout << bl % 2;
        else cout << 1-(bl % 2);
    }
    return 0;
}