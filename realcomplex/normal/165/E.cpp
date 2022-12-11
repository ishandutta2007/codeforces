#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int LOG = 22;
const int N = 1 << LOG;

int answer[N];

int main(){
  fastIO;
  for(int i = 0;i < N; i ++ ){
    answer[i] = -1;
  }
  int n;
  cin >> n;
  queue<int> start;
  int a[n];
  int b;
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
    b = 0;
    for(int j = 0;j < LOG;j ++ ){
      if((a[i] & (1 << j)) == 0){
        b |= (1 << j);
      }
    }
    if(answer[b] == -1){
      answer[b] = a[i];
      start.push(b);
    }
  }
  int x;
  int y;
  while(!start.empty()){
    x = start.front();
    start.pop();
    for(int j = 0;j < LOG;j ++ ){
      if(x & (1 << j)){
        y = x ^ (1 << j);
        if(answer[y] == -1){
          answer[y] = answer[x];
          start.push(y);
        }
      }
    }
  }
  for(int i = 0; i < n;i ++ ){
    cout << answer[a[i]] << " ";
  }
  return 0;
}