#include <stdio.h>
int a,b,c,d,i;
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if (c==d) {
    if (a<d+1) {
      if (b<d+1 || a<d) puts("-1"); else {
        putchar('7'); b--;
        for (i=1; i<=d; i++) {
          while (a>d-i) { putchar('4'); a--; }
          if (i==d) while (b>0) { putchar('7'); b--; } else { putchar('7'); b--; }
        }
      }
    } else {
      if (b<d) puts("-1"); else {
        for (i=1; i<=d; i++) {
          while (a>d+1-i) { putchar('4'); a--; }
          if (i==d) while (b>0) { putchar('7'); b--; } else { putchar('7'); b--; }
        }
        while (a>0) { putchar('4'); a--; }
      }
    }
  } else if (c==d-1) {
    if (a<d || b<d) puts("-1"); else for (i=1; i<=d; i++) {
      if (i==d) while (b>0) { putchar('7'); b--; } else { putchar('7'); b--; }
      while (a>d-i) { putchar('4'); a--; }
    }
  } else if (c==d+1) {
    if (a<c || b<c) puts("-1"); else for (i=1; i<=c; i++) {
      while (a>c-i) { putchar('4'); a--; }
      if (i==c) while (b>0) { putchar('7'); b--; } else { putchar('7'); b--; }
    }
  } else puts("-1");
  return 0;
}