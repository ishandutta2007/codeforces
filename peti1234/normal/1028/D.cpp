#include <bits/stdc++.h>

using namespace std;
int n;
long long mod=1000000007;
priority_queue<long long> buy;
priority_queue<long long> sell;
vector<long long> var;
long long w=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    buy.push(-1);
    sell.push(-INT_MAX);
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (s[1]=='D') {
            if (x<buy.top()) {
                buy.push(x);
            } else if (x>-sell.top()) {
                sell.push(-x);
            } else {
                var.push_back(x);
            }
        } else {
            //cout << x << " " << buy.top() << " " << sell.top() << endl;
            if (x<buy.top()) {
                cout << 0 << endl;
                return 0;
            } else if(x>-sell.top()) {
                cout << 0 << endl;
                return 0;
            } else {
                if (x!=buy.top() && x!=-sell.top()) {
                    w*=2;
                }
                w%=mod;
                for (int i=0; i<var.size(); i++) {
                    int y=var[i];
                    if (y<x) {
                        buy.push(y);
                    }
                    if (y>x) {
                        sell.push(-y);
                    }
                }
                var.clear();
            }
            if (x==buy.top()) {
                buy.pop();
            }
            if (x==-sell.top()) {
                sell.pop();
            }
        }
    }
    w*=(var.size()+1);
    w%=mod;
    cout << w << endl;
    return 0;
}