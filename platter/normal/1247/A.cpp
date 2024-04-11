#include <cstdio>

int main(void) {
    int da,db;
    scanf("%d %d", &da, &db);
    if (da==db) {
        printf("%d0 %d1", da,db);
    }
    else if (da+1==db) {
        printf("%d9 %d0", da,db);
    }
    else if (da==9&&db==1) {
        printf("99 100");
    }
    else {
        printf("-1");
    }
    return 0;
}