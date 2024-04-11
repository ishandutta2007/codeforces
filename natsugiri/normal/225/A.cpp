#include<cstdio>


int n, t;
int main() {
    bool f=1;
    scanf("%d%d", &n, &t);
    for (int i=0; i<n*2; i++) {
        int a;
        scanf("%d", &a);
        if (a==t || 7-t==a) f=0;
    }
    puts(f?"YES":"NO");

    return 0;
}