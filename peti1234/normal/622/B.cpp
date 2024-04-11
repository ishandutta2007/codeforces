#include <bits/stdc++.h>
using namespace std;

int main() {
	int hh, mm;
	char s;
    cin >> hh >> s >> mm;
    int a;
    cin >> a;
    for (int i=0; i<a; i++) {
        mm++;
        if (mm>59) {
            mm=0;
            hh++;
        }
        if (hh>23) {
            hh=0;
        }
    }
    if (hh<10) {
        cout << 0;
    }
    cout << hh << ":";
    if (mm<10) {
        cout << 0;
    }
    cout << mm << "\n";
	return 0;
}