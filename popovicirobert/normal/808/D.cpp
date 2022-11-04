#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int v[MAXN + 1];
long long l[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, rez, pas;
    long long sum = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    if(sum % 2 == 1)
        cout << "NO";
    else {
        for(i = 1; i <= n; i++)
            l[i] = l[i - 1] + v[i];
        for(i = 1; i <= n; i++) {
             long long a, b;
            rez = 0;
            for(pas = 1 << 17; pas; pas >>= 1)
              if(rez + pas <= n) {
                  if(rez + pas >= i)
                    a = l[rez + pas] - v[i];
                  else
                    a = l[rez + pas];
                  b = sum - v[i] - a;
                  if(b - a > v[i])
                    rez += pas;
              }
            rez++;
            if(rez >= i)
                a = l[rez] - v[i];
            else
                a = l[rez];
            b = sum - v[i] - a;
            if(b - a == v[i]) {
                cout << "YES";
                return 0;
            }
            rez = 0;
            for(pas = 1 << 17; pas; pas >>= 1)
              if(rez + pas <= n) {
                  long long a, b;
                  if(rez + pas >= i)
                    a = l[rez + pas] - v[i];
                  else
                    a = l[rez + pas];
                  b = sum - v[i] - a;
                  if(a - b < v[i])
                    rez += pas;
              }
            rez++;
            if(rez >= i)
                a = l[rez] - v[i];
            else
                a = l[rez];
            b = sum - v[i] - a;
            if(a - b == v[i]) {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}