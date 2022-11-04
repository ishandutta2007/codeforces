#include <bits/stdc++.h>

using namespace std;

const long long LINF = (long long) 1e18 + 1e9 + 123;

int n;

int ask(int i) {
    i = (i - 1) % n + 1;
    cout << "? " << i << endl;
    int result;
    cin >> result;
    return result;
}

void answer(int i) {
    if (i != -1) {
        i = (i - 1) % n + 1;
    }
    cout << "! " << i << endl;
    exit(0);
}

int f(int i) {
    return ask(i + n / 2) - ask(i);
}

int sgn(int x) {
    if (x == 0) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int left = 1;
    int right = 1 + n / 2;
    int f_left = f(left);
    int f_right = f(right);
    assert(f_right == -f_left);
    if (f_left % 2 != 0) {
        answer(-1);
    }
    if (f_left == 0) {
        answer(1);
    }
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int f_mid = f(mid);
        if (f_mid == 0) {
            answer(mid);
        }
        if (sgn(f_mid) == sgn(f_left)) {
            left = mid;
            f_left = f_mid;
        } else {
            assert(sgn(f_mid) == sgn(f_right));
            right = mid;
            f_right = f_mid;
        }
    }

    assert(false);

    return 0;
}