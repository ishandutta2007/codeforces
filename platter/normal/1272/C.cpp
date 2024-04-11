#include <cstdio>

char key[26];
int n;
int k;

bool isin(char x) {
    for(int i=0;i<k;i++) {
        if (x==key[i]) {
            return true;
        }
    }
    return false;
}

int main(void) {
    scanf("%d %d\n",&n,&k);
    char str[200001];
    for(int i=0;i<n;i++) {
        scanf("%c",&str[i]);
    }
    scanf("\n");
    for(int i=0;i<k;i++) {
        scanf("%c ",&key[i]);
    }
    long long ret=0;
    long long row=0;
    for(int i=0;i<n;i++) {
        if (isin(str[i])) {
            row+=1;
        }
        else {
            ret+=(row*(row+1))/2;
            row=0;
        }
    }
    ret+=(row*(row+1))/2;
    printf("%lld",ret);
    return 0;
}