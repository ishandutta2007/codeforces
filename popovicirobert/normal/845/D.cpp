#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = (int) 1e9;

stack <int> v;
stack <bool> d;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, t, vcur, vmax;
    ios::sync_with_stdio(false);
    cin >> n;
    ll cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> t;
        if(t == 1) {
            cin >> vcur;
            while(!v.empty() && v.top() < vcur) {
                v.pop();
                cnt++;
            }
        }
        if(t == 2) {
            while(!d.empty() && d.top() == 0) {
                d.pop();
                cnt++;
            }
        }
        if(t == 3) {
            cin >> vmax;
            v.push(vmax);
            while(!v.empty() && v.top() < vcur) {
                v.pop();
                cnt++;
            }
        }
        if(t == 4) {
            d.push(1);
        }
        if(t == 5) {
            while(!v.empty())
                v.pop();
        }
        if(t == 6)
            d.push(0);
    }
    cout << cnt;
    //cin.close();
    //cout.close();
    return 0;
}