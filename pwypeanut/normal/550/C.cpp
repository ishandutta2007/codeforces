#include <bits/stdc++.h>
using namespace std;

string toString(int x) {
    if (x == 0) return "0";
    string S = "";
    while (x > 0) {
        S += (x % 10) + '0';
        x /= 10;
    }
    string T = "";
    for (int i = S.length() - 1; i >= 0; i--) T += S[i];
    return T;
}

bool findSubstring(string A, string B) {
    int aidx = 0, bidx = 0;
    for (bidx = 0; bidx < B.length(); bidx++) {
        if (aidx == A.length()) return false;
        while (A[aidx] != B[bidx]) {
            aidx++;
            if (aidx == A.length()) return false;
        }
        aidx++;
    }
    return true;
}

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < 1000; i += 8) {
        if (findSubstring(S, toString(i))) {
            printf("YES\n%d\n", i);
            return 0;
        }
    }
    printf("NO\n");
}