#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pii> outp;

void solve(int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    int id = mid + 1;
    solve(l,mid);
    solve(mid+1,r);
    for(int i = l ; i <= mid; i ++ ){
        outp.push_back(mp(i, id));
        id ++ ;
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int p = 1;
    while(p * 2 <= n)
        p *= 2;
    solve(1, p);
    if(p != n)
        solve(n - p + 1, n);
    cout << outp.size() << "\n";
    for(auto y : outp)
        cout << y.fi << " " << y.se << "\n";
    return 0;
}