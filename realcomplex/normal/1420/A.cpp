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
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        bool answ=true;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ )
            cin >> a[i];
        for(int i = 0 ; i + 1 < n; i ++ )
            if(a[i] <= a[i + 1])
                answ = false;
        if(answ)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}