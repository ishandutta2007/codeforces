#include <cstdio>

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    /* int aa = (a | b); */
    /* int bb = (c ^ d); */
    /* int cc = (b & c); */
    /* int dd = (a | d); */
    /* int aaa = (aa & bb); */
    /* int bbb = (cc ^ dd); */
    /* int aaaa = (aaa | bbb); */
    int aa = (a ^ b);
    int bb = (c | d);
    int cc = (b & c);
    int dd = (a ^ d);
    int aaa = (aa & bb);
    int bbb = (cc | dd);
    int aaaa = (aaa ^ bbb);
    printf("%d\n", aaaa);
}