#include <bits/stdc++.h>

using namespace std;

struct Team{
  int point;
  int delta;
  int goal;
  string name;

  bool operator <(const Team &rhs) const{
    return make_pair(make_pair(point, delta), make_pair(goal, rhs.name)) >
           make_pair(make_pair(rhs.point, rhs.delta), make_pair(rhs.goal, name));
  }
}t[4];

struct game{
  string a, b;
  int x, y;
}a[6];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  map < string, int > names;

  for(int i = 0; i < 5; ++i) {
    cin >> a[i].a >> a[i].b;
    string r; cin >> r;
    a[i].x = r[0] - '0';
    a[i].y = r[2] - '0';
    ++names[a[i].a];
    ++names[a[i].b];
  }

  int ansx = -1, ansy = -1;

  for(int u = 0; u < 100; ++u) {
    for(int v = 0; v < u; ++v){
      int id = 0;
      string opp;
      for(auto p : names) {
        if(p.second == names["BERLAND"] && p.first != "BERLAND") opp = p.first;
        t[id].point = t[id].delta = t[id].goal = 0;
        t[id++].name = p.first;
      }
      for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 4; ++j) {
          if(t[j].name != a[i].a) continue;
          if(a[i].x > a[i].y) t[j].point += 3;
          if(a[i].x == a[i].y) t[j].point += 1;
          t[j].delta += a[i].x - a[i].y;
          t[j].goal += a[i].x;
        }

        for(int j = 0; j < 4; ++j) {
          if(t[j].name != a[i].b) continue;
          if(a[i].y > a[i].x) t[j].point += 3;
          if(a[i].x == a[i].y) t[j].point += 1;
          t[j].delta += a[i].y - a[i].x;
          t[j].goal += a[i].y;
        }
      }


      for(int j = 0; j < 4; ++j) {
        if(t[j].name != "BERLAND") continue;
        if(u > v) t[j].point += 3;
        if(u == v) t[j].point += 1;
        t[j].delta += u - v;

        t[j].goal += u;
      }


      for(int j = 0; j < 4; ++j) {
        if(t[j].name != opp) continue;
        if(u < v) t[j].point += 3;
        if(u == v) t[j].point += 1;
        t[j].delta += v - u;
        t[j].goal += v;
      }


      sort(t, t + 4);




      if(t[0].name == "BERLAND" || t[1].name == "BERLAND") {
        if(ansx == -1) {
          ansx = u;
          ansy = v;
          continue;
        }
        if(make_pair(u - v, v) < make_pair(ansx - ansy, ansy)) {
          ansx = u;
          ansy = v;
        }
      }
    }
  }

  if(ansx == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << ansx << ":" << ansy;

  return 0;
}