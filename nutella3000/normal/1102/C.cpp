#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
    //freopen('","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    cin >> n >> x >> y;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    if (x > y) {
        cout << n;
    }else{
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] <= x) cnt++;
        }
        if (cnt % 2 == 1) cnt++;
        cout << cnt / 2;
    }
 }