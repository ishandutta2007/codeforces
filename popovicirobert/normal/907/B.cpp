#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))

using namespace std;

char str[20][20];

int main() {
    FILE *fi, *fout;
    //fi = fopen("B.in" ,"r");
    //fout = fopen("B.out" ,"w");
    fi = stdin;
    fout = stdout;
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, l, c;
    //ios::sync_with_stdio(false);
    for(i = 1; i <= 11; i++) {
        if(i != 4 && i != 8)
          for(j = 1; j <= 3; j++)
             fscanf(fi,"%s" ,str[i] + (j - 1) * 3 + 1 + j - 1);
    }
    for(i = 1; i <= 11; i++) {
        for(j = 1; j <= 11; j++) {
            if(str[i][j] != '.' && str[i][j] != 'x' && str[i][j] != 'o')
                str[i][j] = ' ';
        }
    }
    fscanf(fi,"%d%d" ,&l,&c);
    int lin = l % 3, col = c % 3;
    if(lin == 0)
        lin = 3;
    if(col == 0)
        col = 3;
    int cnt = 0;
  //  printf("%d %d\n" ,lin,col);
    for(i = 3 * (lin - 1) + 1; i <= 3 * lin; i++) {
        for(j = 3 * (col - 1) + 1; j <= 3 * col; j++) {
            if(str[i + lin - 1][j + col - 1] == '.') {
                cnt++;
                str[i + lin - 1][j + col - 1] = '!';
            }
        }
    }
    if(cnt == 0) {
        for(i = 1; i <= 11; i++) {
            for(j = 1; j <= 11; j++) {
                if(str[i][j] == '.')
                    str[i][j] = '!';
            }
        }
    }
    for(i = 1; i <= 11; i++) {
        for(j = 1; j <= 11; j++) {
            printf("%c" ,str[i][j]);
        }
        printf("\n");
    }
    //cin.close();
    //cout.close();
    //fclose(fi);
    //fclose(fout);
    return 0;
}