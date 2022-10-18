#include <stdio.h>

int main(){
    long long xa, ya, xb, yb, xc, yc;
    long long ans;
    scanf ("%I64d%I64d%I64d%I64d%I64d%I64d", &xa, &ya, &xb, &yb, &xc, &yc);
    ans=(xb-xa)*(yc-ya) - (yb-ya)*(xc-xa);
    if (ans == 0)
        printf ("TOWARDS\n");
    else {
            if (ans<0)
                printf ("RIGHT\n");
            else printf ("LEFT\n");
        }
    return 0;
}