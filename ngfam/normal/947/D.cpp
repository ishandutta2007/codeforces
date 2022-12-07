#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, q;
char S[N];
char T[N];
int leadA[N][2];
int cntBC[N][2];

int main(){

  scanf("%s%s", S + 1, T + 1);

  n = strlen(S + 1);
  m = strlen(T + 1);

  for(int i = 1; i <= n; ++i){
    if(S[i] == 'A'){
      leadA[i][0] = leadA[i - 1][0] + 1;
    }
    else cntBC[i][0] = 1;


    cntBC[i][0] += cntBC[i - 1][0];
  }

  for(int i = 1; i <= m; ++i){
        if(T[i] == 'A'){
      leadA[i][1] = leadA[i - 1][1] + 1;
    }
    else cntBC[i][1] = 1; 
    cntBC[i][1] += cntBC[i - 1][1];

  }

  scanf("%d", &q);

  while(q--){
    int l, r, x, y;
    scanf("%d%d%d%d", &l, &r, &x, &y);
  
    int a_s = min(r - l + 1, leadA[r][0]);
    int a_t = min(y - x + 1, leadA[y][1]);

    if(a_s < a_t) putchar('0');
    else{
      int bc_s = cntBC[r][0] - cntBC[l - 1][0];
      int bc_t = cntBC[y][1] - cntBC[x - 1][1];

      if(a_s == a_t && bc_s == 0 && bc_t) {
        putchar('0');
        continue;
      }


      if(bc_s + (a_s > a_t) * 2 <= bc_t && bc_s % 2 == bc_t % 2) putchar('1');
      else {
        if(a_s % 3 == a_t % 3 && bc_s  <= bc_t && bc_s % 2 == bc_t % 2) putchar('1');
        else putchar('0');
      }
    }
  }

	return 0;
}