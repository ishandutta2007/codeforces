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
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i = 0 ;i  < n; i ++ ){
            cin >> a[i];
        }
        for(int i = 0 ;i  < n; i ++ )
            cin >> b[i];
        for(int i = 0 ; i < n; i ++ )
            cin >> c[i];
        vector<int> cur = {a[0]};
        for(int i = 1; i < n - 1; i ++ ){
            if(a[i] != cur.back()) cur.push_back(a[i]);
            else cur.push_back(b[i]);
        }
        if(a[n-1] != cur.back() && a[n-1] != cur[0]){
            cur.push_back(a[n-1]);
        }
        else if(b[n-1] != cur.back() && b[n-1] != cur[0]){
            cur.push_back(b[n-1]);
        }
        else{
            cur.push_back(c[n-1]);
        }
        for(auto x : cur)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}