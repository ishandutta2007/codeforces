#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 123;

char s[N];

char prev(char c) {
    return c == 'a' ? 'z' : (char) (c - 1);
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    
    int left = 0;
    while (left + 1 < n && s[left] == 'a') {
        left++;
    }
    int right = left;
    while (right + 1 < n && s[right + 1] != 'a') {
        right++;
    }
    
    for (int i = 0; i < n; i++) {
        if (left <= i && i <= right) {
            printf("%c", prev(s[i]));
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    
    return 0;
}