#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int curnum = 0;

    for (char c : s) {
        int tmp = (int)c;
        while ((tmp + 1) % 256 != curnum) {
            printf("...\n");
            printf(".X.\n");
            curnum = (curnum + 255) % 256;
        }
        printf("...\n");
        printf(".X.\n");
        printf(".X.\n");
        curnum = (curnum + 255) % 256;
    }
    printf("...\n");
}