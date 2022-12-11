#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 9;
vector<int> T[N];

bool vis[N];
int pos[N];
int gen_seq[N];
int p;

int main(){
  fastIO;
  int n;
  cin >> n;
  int x, y;
  for(int i = 0;i < n - 1;i ++ ){
    cin >> x >> y;
    T[x].push_back(y);
    T[y].push_back(x);
  }
  int inq[n];
  for(int i = 0;i < n;i ++ ){
    cin >> inq[i];
    pos[inq[i]] = i;
  }
  queue<int> vv;
  vv.push(1);
  vis[1] = true;
  int node;
  while(!vv.empty()){
    node = vv.front();
    vv.pop();
    gen_seq[p ++ ] = node;
    vector<pii> st;
    for(auto xx : T[node]){
      if(!vis[xx]){
        st.push_back(mp(pos[xx], xx));
      }
    }
    sort(st.begin(), st.end());
    for(auto x : st){
      vv.push(x.se);
      vis[x.se] = true;
    }
  }
  for(int i = 0;i < n;i ++ ){
    if(inq[i] != gen_seq[i]){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}