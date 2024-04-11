#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    int rent[n];
    for(int j = 0;j<n;j++){
        cin >> rent[j];
    }
    int profit = 0;
    for(int j = 0;j<n-1;j++){
        profit = max(profit,rent[j]-(k+rent[j+1]));
    }
    cout << profit;
    return 0;
}