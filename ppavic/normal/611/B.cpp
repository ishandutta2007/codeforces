#include <iostream>
#include <algorithm>

using namespace std;

typedef long long llint;

llint ok_cnt(llint n) {
    llint x = 0, tmp = n;
    while (tmp > 0) {
        tmp /= 2;
        x++;
    }

    //cout << "x is " << x << endl;

    llint res = 0;
    for (llint i = 1; i < x; i++) {
        res += (i - 1);
        //cout << "res " << res << endl;
    }

    //cout << "after step 1, res is " << res << endl;
    tmp = (1LL << x) - 1LL;
    //cout << "tmp is " << tmp << endl;
    llint current;
    for (llint i = 0; i < x; i++) {
        current = (tmp ^ (1LL << i));
        //cout << "current " << current << endl;
        if (current <= n) {
            res += x - i - 1;
            //cout << "ok, res is " << res << endl;
            break;
        }
    }

    return res;
}

int main() {
    llint a, b;
    cin >> a >> b;

    cout << ok_cnt(b) - ok_cnt(a - 1) << endl;

    return 0;
}