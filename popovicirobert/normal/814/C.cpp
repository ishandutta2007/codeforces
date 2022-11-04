#include <bits/stdc++.h>
#define MAXN 1500

int sp[MAXN + 1][26];

char str[MAXN + 1];

int dp[MAXN + 1][26];

int main() {
    FILE * fi, * fout;
    int i, n, len, q, x;
    char ch;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d " ,&n);
    fscanf(fi,"%s " ,&str);
    for(ch = 0; ch < 26; ch++)
      for(i = 1; i <= n; i++)
        sp[i][ch] = sp[i - 1][ch] + (str[i - 1] == ch + 'a');
    for(ch = 0; ch < 26; ch++)
      for(len = 1; len <= n; len++)
        for(i = len; i <= n; i++)
            dp[len - (sp[i][ch] - sp[i - len][ch])][ch] = std::max(dp[len - (sp[i][ch] - sp[i - len][ch])][ch], len);
    for(ch = 0; ch < 26; ch++)
      for(i = 1; i <= n; i++)
        dp[i][ch] = std::max(dp[i][ch], dp[i - 1][ch]);
    fscanf(fi,"%d" ,&q);
    while(q > 0) {
       q--;
       fscanf(fi,"%d %c " ,&x ,&ch);
       //printf("%d %c\n" ,x,ch);
       fprintf(fout,"%d\n" ,dp[x][ch - 'a']);
    }
    //fclose(fi);
   // fclose(fout);
    return 0;
}