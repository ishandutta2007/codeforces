#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;


int a[MAXN + 1], b[MAXN + 1];
int smen[MAXN + 1];
int n, m;

inline bool check(int r) {
   int i;
   memset(smen, 0, sizeof(smen));
   for(i = 1; i <= m; i++) {
       int rez1, rez2;
       rez1 = rez2 = -1;
       for(int pas = 1 << 16; pas; pas >>= 1) {
           if(rez1 + pas <= n && b[i] - a[rez1 + pas] > r)
              rez1 += pas;
           if(rez2 + pas <= n && a[rez2 + pas] - b[i] <= r)
              rez2 += pas;
       }
       smen[rez1 + 1]++;
       smen[rez2 + 1]--;
   }
   for(i = 1; i <= n; i++) {
       smen[i] += smen[i - 1];
       if(smen[i] == 0)
          return 0;
   }
   return 1;
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    int rez = -1;
    for(int pas = 1 << 30; pas; pas >>= 1)
        if(check(rez + pas) == 0)
           rez += pas;
    cout << rez + 1;
  //  cin.close();
  //  cout.close();
    return 0;
}