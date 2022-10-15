#include <iostream>

using namespace std;

int n;
int c[30];
int x, r;

void print(char c, int q) {
    for (int i = 1; i <= q; i++) cout << c;
}

int ss;
int syt(int a, int b) {
    if (b == 0) return a;
    return syt(b,a%b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i]%2 == 1) {x++; r = i;}
        ss = syt(ss,c[i]);
    }
    if (n == 1) {
        cout << c[n] << "\n";
        print('a',c[n]);
        cout << "\n";
        return 0;
    }
    if (x > 1) {
        cout << "0\n";
        for (int i = 1; i <= 26; i++) {
            print('a'+i-1,c[i]);
        }
        cout << "\n";
        return 0;
    }
    if (x == 1) {
        cout << ss << "\n";
        for (int i = 1; i <= ss; i++) {
            print('a'+r-1,c[r]/ss);
            for (int i = 1; i <= 26; i++) {
                if (i == r) continue;
                print('a'+i-1,c[i]/ss/2);
            }
            for (int i = 26; i >= 1; i--) {
                if (i == r) continue;
                print('a'+i-1,c[i]/ss/2);
            }
        }
        cout << "\n";
    } else {
        cout << ss << "\n";
        for (int i = 1; i <= ss/2; i++) {
            for (int j = 1; j <= 26; j++) {
                print('a'+j-1,c[j]/ss);
            }
            for (int j = 26; j >= 1; j--) {
                print('a'+j-1,c[j]/ss);
            }
        }
        cout << "\n";
    }
}