#include <iostream>
#include <map>

using namespace std;

int n;
string s;
map<pair<int,int>,int> d;

int calc(int a, int b, char c) {
    if (a == b) return s[a] != c;
    pair<int,int> p = {a,b};
    if (d.count(p)) return d[p];
    int k = b-a+1;
    int c1 = 0;
    for (int i = 0; i < k/2; i++) {
        if (s[a+i] == c) c1++;
    }
    int d1 = k/2-c1+calc(a+k/2,b,c+1);
    int c2 = 0;
    for (int i = k/2; i < k; i++) {
        if (s[a+i] == c) c2++;
    }
    int d2 = k/2-c2+calc(a,a+k/2-1,c+1);
    int r = min(d1,d2);
    d[p] = r;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        d.clear();
        cin >> n;
        cin >> s;
        cout << calc(0,n-1,'a') << "\n";
    }
}