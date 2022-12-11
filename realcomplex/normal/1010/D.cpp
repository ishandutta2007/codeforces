#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)1e6 + 91;
int bit[N];
int op[N];
vector<int>nex[N];

/*
 * 1 - AND
 * 2 - OR
 * 3 - XOR
 * 4 - NOT
 * 5 - IN
 * */
 
void calc(int node){
  for(auto x : nex[node])
    calc(x);
  if(op[node] == 5){
    return;
  }
  if(op[node] == 1){
    bit[node] = (bit[nex[node][0]] & bit[nex[node][1]]);
  }
  else if(op[node] == 2){
    bit[node] = (bit[nex[node][0]] | bit[nex[node][1]]);
  }
  else if(op[node] == 3){
    bit[node] = (bit[nex[node][0]] ^ bit[nex[node][1]]);
  }
  else{
    bit[node] = (!bit[nex[node][0]]);
  }
}
 
int change[N];

void visit(int node){
  if(change[node] == 0 or op[node] == 5){
    for(auto x : nex[node]){
      visit(x);
    }
    return;
  }
  int a = nex[node][0];
  int b = a;
  if(nex[node].size() == 2)
    b = nex[node][1];
  if(op[node] == 1){
    if(bit[node] == ((1 - bit[a]) & bit[b]))
      change[a] = 0;
    else
      change[a] = 1;
    if(bit[node] == (bit[a] & (1 - bit[b])))
      change[b] = 0;
    else
      change[b] = 1;
  }
  else if(op[node] == 2){
    if(bit[node] == ((1 - bit[a]) | bit[b]))
      change[a] = 0;
    else
      change[a] = 1;
    if(bit[node] == (bit[a] | (1 - bit[b])))
      change[b] = 0;
    else
      change[b] = 1;
  }
  else if(op[node] == 3){
    if(bit[node] == ((1 - bit[a]) ^ bit[b]))
      change[a] = 0;
    else
      change[a] = 1;
    if(bit[node] == (bit[a] ^ (1 - bit[b])))
      change[b] = 0;
    else
      change[b] = 1;
  }
  else if(op[node] == 4){
    change[a] = 1;
  }
  for(auto x : nex[node]){
    visit(x);
  }
}
 
int main(){
  fastIO;
  int n;
  cin >> n;
  string oper;
  int i1, i2;
  vector<int> leaf;
  for(int i = 1; i <= n;i ++ ){
    cin >> oper;
    if(oper == "AND"){
      op[i] = 1;
      cin >> i1 >> i2;
      nex[i].push_back(i1);
      nex[i].push_back(i2);
    }
    else if(oper == "OR"){
      op[i] = 2;
      cin >> i1 >> i2;
      nex[i].push_back(i1);
      nex[i].push_back(i2);
    }
    else if(oper == "XOR"){
      op[i] = 3;
      cin >> i1 >> i2;
      nex[i].push_back(i1);
      nex[i].push_back(i2);
    }
    else if(oper == "NOT"){
      op[i] = 4;
      cin >> i1;
      nex[i].push_back(i1);
    }
    else{
      op[i] = 5;
      cin >> bit[i];
      leaf.push_back(i);
    }
  }
  calc(1);
  change[1] = 1;
  visit(1);
  for(auto x : leaf){
    cout << (bit[1]^change[x]);
  }
  return 0;
}