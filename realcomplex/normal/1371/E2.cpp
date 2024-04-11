#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

int main(){
    fastIO;
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int soln = 1;
    for(int i = 0 ; i < n; i ++ ){
        soln = max(soln, a[i] - i);
    }
    int l = soln, r = (int)1e9 + 500000;
    int mid;
    bool has;
    int aa;
    int xx;
    while(l < r){
        has = true;
        mid=(l+r)/2;
        aa = mid;
        xx = 0;
        for(int i = 0 ; i < n; i ++ ){
            while(xx<n && mid+i>=a[xx])
                xx++;
            if(xx - i >= p) has = false;
        }
        if(has)
            l=mid+1;
        else
            r=mid;
    }
    cout << l - soln << "\n";
    for(int i = soln; i < l ; i ++ )
        cout << i << " ";
    cout << "\n";
    return 0;
}