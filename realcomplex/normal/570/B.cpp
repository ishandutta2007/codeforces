#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    int n,m;
    cin >> n >> m;
    if(m == n && n == 1){
        cout << m;
    }
    else{
        if(n == m || (n-m) <= (m-1)){
            cout << m-1;
        }
        else{
            cout << m+1;
        }
    }
    return 0;
}