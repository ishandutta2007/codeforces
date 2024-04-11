#include <bits/stdc++.h>
int a[28];
int main() {
    int n, k;
    std::string st;
    std::cin >> n >> k >> st;
    for (char i : st)
    	a[i - 'a']++;
    if (*std::max_element(a, a + 28) <= k) puts("YES");
    else puts("NO");
}