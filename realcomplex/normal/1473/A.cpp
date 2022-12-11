#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n,d;
        cin >> n >> d;
        vector<int> a(n);
        for(int i =  0 ; i < n; i ++ ){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(a[0] + a[1] <= d || a[n-1] <= d){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}