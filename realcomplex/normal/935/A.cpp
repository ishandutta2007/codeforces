#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i<n;i++){
        if((n-i)%i==0)ans++;
    }
    cout << ans << "\n";
    return 0;
}