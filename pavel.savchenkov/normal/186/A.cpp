#include <cstdio>
#include <iostream>
#include <cstring>
#include <memory.h>

#define forn(i, n) for (int i=0; i<(int)n; i++)

using namespace std;
char a[100500];
char b[100500];

bool solve()
{
     int n = (int)strlen(a);
     int m = (int)strlen(b);
     if (n != m) return 0;
     int f = 0;
     int i1=-1, i2=-1;
     
     for (int i=0; i < n; i++)
      if (a[i] != b[i] && i1 == -1) i1 = i, f++; else
       if (a[i] != b[i] && i2 == -1) i2 = i, f++; else
        if (a[i] != b[i]) f++;

     if (f > 2 || f == 1) return 0;
     if (f == 2)
           return b[i1] == a[i2] && b[i2] == a[i1];
     return 1;
}

int main() {
 gets(a);
 gets(b); 
 
 puts(solve() ? "YES" : "NO");
 
 return 0;
}