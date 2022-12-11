#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;

int main(){
    fastIO;
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ )
        cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> ans;
    int ch;
    for(int k = 1; k <= 4000; k ++ ){
        vector<int> f;
        for(int i = 0 ; i < n; i ++ ){
            f.push_back(min(n, n-(a[i] - k)));
        }
        ch = 1;
        for(int i = 0 ; i < n; i ++ ){
            if(f[i] - i <= 0) {
                ch = 0;
                break;
            }
            if((f[i] - i) % p == 0) ch = 0;
        }
        if(ch)
            ans.push_back(k);
    }
    cout << ans.size() << "\n";
    for(auto x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}