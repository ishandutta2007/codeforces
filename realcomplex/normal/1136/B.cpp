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
    int n, k;
    cin >> n >> k;
    int dis = min(n-k, k-1) + (n - 1);
    cout << dis + 2 * n + 1;
    return 0;
}