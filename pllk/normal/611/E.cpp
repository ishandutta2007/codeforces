#include <iostream>
#include <set>

using namespace std;

int n;
int a, b, c;
multiset<int> s;
int z;

void lol1() {
    while (s.size() > 0) {
        auto it = s.upper_bound(b);
        bool ok = false;
        if (it != s.begin()) {
            it--;
            if (it != s.begin()) ok = true;
        }
        if (ok) {
            int x = a;
            int d = 0;
            auto it = s.upper_bound(x);
            if (it != s.begin()) {
                it--;
                s.erase(s.find(*it));
            } else d += a;
            x = b+d;
            it = s.upper_bound(x);
            if (it != s.begin()) {
                it--;
                s.erase(s.find(*it));
            } else d += b;
            x = c+d;
            it = s.upper_bound(x);
            if (it != s.begin()) {
                it--;
                s.erase(s.find(*it));
            }
            z++;
        } else {
            auto it = s.upper_bound(a+b);
            if (it != s.begin()) {
                it--;
                s.erase(s.find(*it));
            }
            it = s.upper_bound(c);
            if (it != s.begin()) {
                it--;
                s.erase(s.find(*it));
            }
            z++;
        }
    }
}


void lol2() {
    while (s.size() > 0 && *s.rbegin() > c) {
        s.erase(s.find(*s.rbegin()));
        auto it = s.upper_bound(c);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        }
        z++;
    }
    while (s.size() > 0) {
        int x = a;
        int d = 0;
        auto it = s.upper_bound(x);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        } else d += a;
        x = b+d;
        it = s.upper_bound(x);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        } else d += b;
        x = c+d;
        it = s.upper_bound(x);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        }
        z++;
    }
}

int main() {
    cin >> n;
    cin >> a >> b >> c;
    for (int i = 0; i < 5; i++) {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (*s.rbegin() > a+b+c) {
        cout << "-1\n";
        return 0;
    }
    while (s.size() > 0 && *s.rbegin() > b+c) {
        s.erase(s.find(*s.rbegin()));
        z++;
    }
    while (s.size() > 0 && *s.rbegin() > a+c) {
        s.erase(s.find(*s.rbegin()));
        auto it = s.upper_bound(a);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        }
        z++;
    }
    while (s.size() > 0 && *s.rbegin() > a+b && *s.rbegin() > c) {
        s.erase(s.find(*s.rbegin()));
        auto it = s.upper_bound(b);
        if (it != s.begin()) {
            it--;
            s.erase(s.find(*it));
        }
        z++;
    }
    if (c >= a+b) lol1();
    else lol2();
    cout << z << "\n";
}