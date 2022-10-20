#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000000
#define N

using namespace std;

int a , b, c;
vector <int> kq;
long long sum;

int kt(long long x) {
    if(x <= 0 || x >= MAX) return 0;
    int sl = 0;
    while(x) {
        sl += x % 10;
        x /= 10;
    }
    return sl;
}

int main() {
    //fi, fo;
    cin >> a >> b >> c;
    for(int i = 1; i <= 81; i++) {
        sum = 1;
        for(int j = 1; j <= a; j++) sum *= i;
        sum *= b;
        sum += c;
        if(kt(sum) == i) kq.push_back(sum);
    }
    cout << kq.size() << endl;
    for(int i = 0; i < (int)kq.size(); i++) printf("%d ", kq[i]);
}