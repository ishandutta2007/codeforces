#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[5555][1111];
int mark[5555];

struct logic{
  int idx;
  int opp;
  int fin;
}arr[5555];

map < string, int > number;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "W", stdout);
  #endif // pts
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  string solve;
  getline(cin, solve);
  for(int i = 1; i <= n; ++i){
    getline(cin, solve);
    string value;
    int pos = 0;
    while(solve[pos] != ' '){
      value += solve[pos];
      ++pos;
    }
    number[value] = i;
    ++pos;
    while(solve[pos] != ' '){
      ++pos;
    }
    ++pos;
    if(solve[pos] == '0' || solve[pos] == '1'){
      mark[i] = 1;
      for(int j = pos; j < pos + m; ++j){
        a[i][j - pos] = solve[j] - '0';
      }
      continue;
    }
    if(solve[pos] == '?'){
      arr[i].idx = -1;
      ++pos;
    }
    else{
      string name;
      while(solve[pos] != ' '){
        name += solve[pos];
        ++pos;
      }
      arr[i].idx = number[name];
    }
    ++pos;
    if(solve[pos] == 'X'){
      arr[i].opp = 0;
      pos += 4;
    }
    else{
      if(solve[pos] == 'O'){
        arr[i].opp = 1;
        pos += 3;
      }
      else if(solve[pos] == 'A'){
        arr[i].opp = 2;
        pos += 4;
      }
    }
    if(solve[pos] == '?'){
      arr[i].fin = -1;
      ++pos;
    }
    else{
      string name;
      for(; pos < solve.size(); ++pos){
        name += solve[pos];
      }
      arr[i].fin = number[name];
    }
  }
  string maxval, minval;
  for(int bit = 0; bit < m; ++bit){
    int big = 0, answer = 0, soup = 0, small = 12746, ius = 0;
    for(int value = 0; value < 2; ++value){
      int cnt = 0;
      for(int i = 1; i <= n; ++i){
        if(mark[i] == 1){
          cnt += a[i][bit];
          continue;
        }
        int l = (arr[i].idx == -1 ? value : a[arr[i].idx][bit]);
        int r = (arr[i].fin == -1 ? value : a[arr[i].fin][bit]);
        if(bit == 0 && i == 3 && value == 1){
          //cerr << value << " : " << l << " " << r << endl;
        }
        int result;
        if(arr[i].opp == 0){
          result = l ^ r;
        }
        if(arr[i].opp == 1){
          result = l | r;
        }
        if(arr[i].opp == 2){
          result = l & r;
        }
        cnt += result;
        a[i][bit] = result;
        if(i == 3 && bit == 0){
      //    cout << value << " : " << result << endl;
        }
      }
      if(cnt > answer){
        big = value;
        answer = cnt;
      }
      if(cnt < small){
        small = cnt;
        ius = value;
      }
    }
    maxval += (big) + '0';
    minval += (ius + '0');
  }
  cout << minval << endl << maxval;
  return 0;
}