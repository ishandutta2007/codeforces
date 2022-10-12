#include<bits/stdc++.h>
using namespace std;

char s[200002];
bool ga[200002];
int bef[200002];

int main(){
    gets(s);
    int len = strlen(s);

    for (int i=0; i<len; i++) bef[i] = i-1;

    for (int i=0; i<len; i++) {
        if (bef[i] == -1) continue;
        if (s[i] == s[bef[i]]) {
            bef[i+1] = bef[bef[i]];
            ga[i] = 1, ga[bef[i]] = 1;
        }
    }

    for (int i=0; i<len; i++) if (ga[i]) continue; else printf("%c", s[i]);
    printf("\n");

    return 0;
}