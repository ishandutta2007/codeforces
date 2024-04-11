
#include <cstdio>

int main() {
    int n;
    char s[123];
    scanf("%d", &n);
    for (int i = n + 1; ;i++) {
        sprintf(s, "%d", i);
        int good = 1;
        for (int j = 0; j< 4; j++) {
            for (int k = j + 1; k <4; k++) if (s[j] == s[k]) good = 0;
        }
        if (good){
            puts(s);
            return 0;
        }
    }
}