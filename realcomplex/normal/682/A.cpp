#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

int main(){

    ll n,m;
    cin >> n >> m;
    ll pairs = 0;
    pairs += ((n/5)*(m/5))*5;
    pairs += (n/5)*(m%5);
    pairs += (m/5)*(n%5);
    if(n%5 >= 1 && m%5 >= 4){
        pairs++;
    }
    if(n%5 >= 2 && m%5 >= 3){
        pairs++;
    }
    if(n%5 >= 3 && m%5 >= 2){
        pairs++;
    }
    if(n%5 >= 4 && m%5 >= 1){
        pairs++;
    }
    cout << pairs;
    return 0;
}