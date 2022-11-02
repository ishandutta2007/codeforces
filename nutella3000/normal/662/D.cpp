#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int log_10(int a) {
    int ans = 0;
    while(a > 0) {
        a /= 10;
        ans++;
    }
    return ans;
}
int pw(int a,int b) {
    int u = a;
    for(int i = 1;i < b;i++) a *= u;
    return a;
}
int f(int min,int a,int sz) {
    while(true) {
        if (a >= min) break;
        int d = pw(10,sz);
        if (min % d > a) a += d;
        a += (min / d % 10) * d;
        sz++;
    }
    return a;
}
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        s.erase(0,4);
        int a = atoi(s.c_str());
        int min = 1989;
        for(int j = 1;j < s.size();j++) {
            min = f(min,a % pw(10,j),j) + 1;
        }
        cout << f(min,a,s.size()) << '\n';
    }
}