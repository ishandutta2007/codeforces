#include <stdio.h>
char s1[9],s2[9],s3[9];
char win(char a, char b, char c) {
  if (a=='r') return (b=='s') && (c=='s');
  if (a=='s') return (b=='p') && (c=='p');
  return (b=='r') && (c=='r');
}
int main() {
  gets(s1); gets(s2); gets(s3);
  if (win(s1[0],s2[0],s3[0])) { puts("F"); return 0; }
  if (win(s2[0],s1[0],s3[0])) { puts("M"); return 0; }
  if (win(s3[0],s2[0],s1[0])) { puts("S"); return 0; }
  puts("?"); return 0;
}