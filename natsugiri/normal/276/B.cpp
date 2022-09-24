#include<cstdio>

char s[1024];
int cnt[26], od;
int main() {
    scanf("%s", s);
    for (int i=0; s[i]; i++) cnt[s[i]-'a']++;
    for (int i=0; i<26; i++) if (cnt[i]&1) od++;
    if (od==0 || od&1) puts("First");
    else puts("Second");
    return 0;
}