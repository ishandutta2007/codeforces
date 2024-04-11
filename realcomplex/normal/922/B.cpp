#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    int n;
    cin >> n;
    int c;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            c=(i^j);
            if(c<j or c>n)continue;
            if(c<i+j and j<i+c and i<j+c)ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}