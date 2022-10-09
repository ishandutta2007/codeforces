#include <bits/stdc++.h>
std::map<long long,int>m;
char s[5000];
int n, ans;
long long hash;
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        hash = 0;
        for (int i = 0; i < strlen(s); ++i) hash = hash * 31 + s[i] - 'A' + 1;
        m[hash]++;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        hash = 0;
        for (int i = 0; i < strlen(s); ++i) hash = hash * 31 + s[i] - 'A' + 1;
        m[hash]--;
    }
    for(auto it = m.begin(); it != m.end(); it++)
       ans += std::max(0,it->second);
    printf("%d", ans);
    return 0;
}