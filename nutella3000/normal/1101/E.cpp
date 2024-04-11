#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
struct w {
    int l,r,ind;
    w(int left,int right,int in) {
        l = left;
        r = right;
        ind = in;
    }
    w() {}
    bool operator <(const w &a)const {
        if (a.l == l) {
            return a.r > r;
        }
        return a.l > l;
    }
};
int main() {
   //freopen("transform.in", "r", stdin);
    //freopen("transform.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    int mn = 0;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        if (s == "+") {
            int x,y;
            cin >> x >> y;
            mx = max(mx,max(x,y));
            mn = max(mn,min(x,y));
        }else{
            int x,y;
            cin >> x >> y;
            if (mx > max(x,y) || mn > min(x,y)) {
                cout << "NO" << '\n';
            }else cout << "YES" << '\n';
        }
    }
}