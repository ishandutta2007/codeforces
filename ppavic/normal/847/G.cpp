#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[10];

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        string str;
        cin >>str;
        for (int i=0; i<7; ++i) {
            if (str[i]=='1') p[i]++;
        }
    }
    int sol=0;
    for (int i=0; i<7; ++i) {
        sol=max(sol, p[i]);
    }
    printf("%d", sol);
}