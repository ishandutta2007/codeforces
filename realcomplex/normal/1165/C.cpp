#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nx[n];
    nx[n-1] = -1;
    for(int i = n - 2; i >= 0 ; i -- ){
        if(s[i] == s[i + 1])
            nx[i] = nx[i + 1];
        else
            nx[i] = i + 1;
    }
    string nw;
    int i = 0;
    while(i < n){
        if(nx[i] == -1)
            break;
        nw.push_back(s[i]);
        nw.push_back(s[nx[i]]);
        i=nx[i];
        ++i;
    }
    cout << n - nw.size() << "\n";
    cout << nw;
    return 0;
}