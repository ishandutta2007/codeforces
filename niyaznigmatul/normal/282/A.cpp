#include <cstdio>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;

}


char s[123];

int main() {
    gets(s);
    int n = 0;
    for (int i = 0;s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0';
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        gets(s);
        for (int j = 0; s[j];j++){
            if (s[j] == '+') {
                ++x;
                break;
            } else if (s[j] == '-') {
                --x;
                break;
            }
        }        
    }
    printf("%d\n", x);
}