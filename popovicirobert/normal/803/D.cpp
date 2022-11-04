#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

char str[MAXN + 1];

inline bool check(int n, int len, int k) {
    int i, j, cnt = 0;
    i = 0;
    while(i < n) {
        j = min(i + len - 1, n - 1);
        cnt++;
        if(j < n - 1) {
            while(j > i && isalpha(str[j]))
                j--;
            if(i == j)
                return 0;
        }
        i = j + 1;
    }
    return cnt <= k;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    FILE *fi, *fout;
    int k, n, rez, pas;
    //fi = fopen("a.in" ,"r");
    //fout = fopen("a.out" ,"w");
    fi = stdin;
    fout = stdout;
    //ios::sync_with_stdio(false);
    fscanf(fi,"%d " ,&k);
    char ch = fgetc(fi);
    n = 0;
    while(ch != '\n') {
        str[n++] = ch;
        ch = fgetc(fi);
    }
    rez = 0;
    for(pas = 1 << 20; pas; pas >>= 1)
        if(check(n, rez + pas, k) == 0)
           rez += pas;
    fprintf(fout,"%d" ,rez + 1);
   // cin.close();
   // cout.close();
   //fclose(fi);
   //fclose(fout);
    return 0;
}