#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 300;

struct data{
  int minute, id;
  char type, color;
} a[N];

string Aname, Hname;
int sl[N], n;

bool cmp(data x, data y){
  return x.minute < y.minute;
};

void Inkq(int i) {
  if(a[i].type == 'h') cout << Hname << " " << a[i].id << " " << a[i].minute << endl;
  else cout << Aname << " " << a[i].id - 100 << " " << a[i].minute << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> Hname >> Aname;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i].minute >> a[i].type >> a[i].id >> a[i].color;
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; i++) {
    if(a[i].type == 'a') a[i].id += 100;
    if(a[i].color == 'r') {
      if(sl[a[i].id] < 2) {
        sl[a[i].id] = 2;
        Inkq(i);
      }
    }
    if(sl[a[i].id] < 2) {
      sl[a[i].id]++;
      if(sl[a[i].id] == 2) Inkq(i);
    }
  }
  return 0;
}