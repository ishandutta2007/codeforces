#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

template<typename T>
T max(T&& a) {
	return a;
}

template<typename T, typename... Args>
T max(T&& a, Args&&... args) {
	T b = max(args...);
	return (a < b ? b : a);
}

template<typename T>
T min(T&& a) {
	return a;
}

template<typename T, typename... Args>
T min(T&& a, Args&&... args) {
	T b = min(args...);
	return (a < b ? a : b);
}



int main() {
#ifndef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    /*
    int ;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    */

    vector<int> answer = {0, 0, 0, 2, 3};

    int i, n;
    cin >> n;

    auto ask = [&](int a, int b, const string& str) {
        cout << str << " " << a << " " << b << endl;
        int ans;

        #ifdef HOME
            if(str == "XOR") {
                ans = (answer[a] ^ answer[b]);
            }
            if(str == "OR") {
                ans = (answer[a] | answer[b]);
            }
            if(str == "AND") {
                ans = (answer[a] & answer[b]);
            }
        #else
            cin >> ans;
        #endif

        return ans;
    };

    vector<int> b(n + 1);
    map<int, int> mp;
    for(int i = 2; i <= n; i++) {
        b[i] = ask(1, i, "XOR");
        mp[b[i]] = i;
    }

    vector<int> a(n + 1);
    bool found = false;

    for(i = 2; i <= n; i++) {
        if(mp[b[i]] && mp[b[i]] != i) {
            int x = i, y = mp[b[i]];
            a[x] = ask(x, y, "OR");
            a[1] = (b[x] ^ a[x]);
            found = true;
            break;
        }
        if(b[i] == 0) {
            a[1] = ask(1, i, "OR");
            found = true;
            break;
        }
    }

    if(!found) {
        int bit = 0;
        a[1] = ask(1, mp[1 << bit], "AND");

        for(i = 2; i <= n; i++) {
            if((b[i] & (1 << bit)) == 0) {
                int or_value = ask(1, i, "OR");
                if(or_value & (1 << bit)) {
                    a[1] |= (1 << bit);
                }
                break;
            }
        }
    }

    for(i = 2; i <= n; i++) {
        a[i] = (a[1] ^ b[i]);
    }

    cout << "! ";
    for(i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}