#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

int n;
int must[N];
char b[N][5];
int done[N][2];
map < string, int > avail;
pair < string, string > read[N];
pair < string, string > a[N];
string result[N];
map < string, vector < pair < int, int > > > adj;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> read[i].first >> read[i].second;
    b[i][1] = read[i].first[0];
    b[i][2] = read[i].first[1];
    b[i][3] = read[i].first[2];
    b[i][4] = read[i].second[0];
    a[i].first += (b[i][1]);
    a[i].first += b[i][2];
    a[i].first += b[i][3];
    a[i].second += b[i][1];
    a[i].second += b[i][2];
    a[i].second += b[i][4];
    adj[a[i].first].push_back(make_pair(i, 0));
    adj[a[i].second].push_back(make_pair(i, 1));
  }
  queue < pair < int, int > > bfs;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      if(a[i] == a[j]){
        puts("NO");
        return 0;
      }
      if(a[i].first == a[j].first){
        if(avail[a[i].second] != 0 && avail[a[i].second] != i){
          puts("NO");
          return 0;
        }
        if(avail[a[j].second] != 0 && avail[a[j].second] != j){
          puts("NO");
          return 0;
        }
        must[i] = 1;
        must[j] = 1;
        avail[a[i].second] = i;
        avail[a[j].second] = j;
        result[i] = a[i].second;
        result[j] = a[j].second;
        bfs.push(make_pair(i, 1));
        bfs.push(make_pair(j, 1));
        done[i][1] = 1;
        done[j][1] = 1;
      }
    }
  }
  while(!bfs.empty()){
    pair < int, int > curr = bfs.front();
    bfs.pop();
    int idx = curr.first;
    string value = (curr.second ? a[idx].second : a[idx].first);
    for(auto p : adj[value]){
      if(idx == p.first){
        continue;
      }
      if(done[p.first][p.second] == 1){
        puts("NO");
        return 0;
      }
      if(done[p.first][1 - p.second] == 1){
        continue;
      }
      done[p.first][1 - p.second] = 1;
      result[p.first] = (p.second ? a[p.first].first : a[p.first].second);
      bfs.push(make_pair(p.first, 1 - p.second));
    }
  }
  for(int i = 1; i <= n; ++i){
    if(result[i] == ""){
      result[i] = a[i].first;
    }
  }
  cout << "YES" << endl;
  for(int i = 1; i <= n; ++i){
    cout << result[i] << endl;
  }
  return 0;
}