#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, d, currentPad, nextPad, ans;
string str;
bool pos;

int main() {
    ans = 1;
    currentPad = 1;
	cin >> n >> d >> str;
    while (currentPad < n-d) {
        pos = false;
        for (int i=currentPad+1; i <= currentPad+d; ++i) {
            if (str[i-1] == '1') {
                nextPad = i;
                pos = true;
            }
        }

        if (!pos) {
            cout << -1;
            return 0;
        }
        ans++;
        currentPad = nextPad;
    }
	
    cout << ans;
	return 0;
}