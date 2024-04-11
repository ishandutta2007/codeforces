#include <cstdio>
#include <string>
#include <cstring>
#include <memory.h>
#include <iostream>

using namespace std;

char w[200];
char s[200][200];
int n;
bool f[200];

bool com(char a, char b)
{
 if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
 if (b >= 'A' && b <= 'Z') b += 'a' - 'A';
 return a == b;
}

int main() {
 memset(f, 0, sizeof f);
 scanf("%d\n", &n);
 for (int i = 0; i < n; i++)
  gets(s[i]);
 gets(w);
 
 for (int i = 0; i < n; i++)
  for (int start = 0; w[start]; start++)
  {
   bool ok = 1;
   if (start + strlen(s[i]) > strlen(w)) continue;
   
   for (int j = start; s[i][j - start]; j++)
    if  (!com(s[i][j - start], w[j])) { ok = 0; break; }
    
   if  (!ok) continue;
   
   for (int j = start; s[i][j - start]; j++)
    f[j] = 1;
  }
  
 char let = getchar();

 for (int i = (int)strlen(w) - 1; i >= 0; i--)
  if (f[i])
  {
   if  (com(let, w[i])) 
    {
     if  (w[i] <= 'Z') w[i] = 'A'; else w[i] = 'a';
     if  (!com(let, 'a')) continue;
     if  (w[i] <= 'Z') w[i] = 'B'; else w[i] = 'b';
     continue;  
    }
   if  (w[i] <= 'Z') w[i] = let - 'a' + 'A'; else w[i] = let;
  }
 
 puts(w);
 return 0;
}