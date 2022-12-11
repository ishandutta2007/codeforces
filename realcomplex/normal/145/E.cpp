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
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e6 + 192;

struct Node{
  int c4;
  int c7;
  int c47;
  int c74;
  int lazy;
};

Node Tree[N * 4 + 1923];
int E[N];

void merge(int idx){
  int l = idx * 2;
  int r = l + 1;  
  Tree[idx].c4 = Tree[l].c4 + Tree[r].c4;
  Tree[idx].c7 = Tree[l].c7 + Tree[r].c7;
  Tree[idx].c47 = max(Tree[l].c47 + Tree[r].c7, Tree[l].c4 + Tree[r].c47);
  Tree[idx].c74 = max(Tree[l].c74 + Tree[r].c4, Tree[r].c74 + Tree[l].c7);
}

void build(int index, int cl, int cr, int tl, int tr){
  Tree[index].c4 = 0;
  Tree[index].c7 = 0;
  Tree[index].c47 = 0;
  Tree[index].c74 = 0;
  Tree[index].lazy = 0;
  if(cl == cr){
    if(E[cl] == 4)
      Tree[index].c4 = 1;
    else
      Tree[index].c7 = 1;
    Tree[index].c47 = 1;
    Tree[index].c74 = 1;
    return;
  }
  int md = (cl + cr)/2;
  build(index * 2, cl, md, tl, tr);
  build(index * 2 + 1, md + 1, cr, tl, tr);
  merge(index);
}

void push(int index, int cl, int cr){
  if(Tree[index].lazy){
    swap(Tree[index].c4, Tree[index].c7);
    swap(Tree[index].c47, Tree[index].c74);
    if(cl != cr){
      Tree[index * 2].lazy ^= 1;
      Tree[index * 2 + 1].lazy ^= 1;
    }
    Tree[index].lazy = 0;
  }
}

void invert(int index, int cl, int cr, int tl, int tr){
  push(index, cl, cr);
  if(cl > tr)
    return;
  if(cr < tl)
    return;
  if(cl >= tl and cr <= tr){
    Tree[index].lazy ^= 1;
    push(index, cl, cr);
    return ;
  }
  int md = (cl + cr)/2;
  invert(index * 2, cl, md, tl, tr);
  invert(index * 2 + 1, md + 1, cr, tl, tr);
  merge(index);
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  char k;
  for(int i = 0;i < n;i ++ ){
    cin >> k;
    E[i] = k - '0';
  }
  build(1, 0, n-1, 0, n-1);
  string op;
  int l, r;
  for(int i = 0;i < q;i ++ ){
    cin >> op;
    if(op == "count"){
      cout << Tree[1].c47 << "\n";
    }
    else{
      cin >> l >> r;
      --l;
      --r;
      invert(1, 0, n - 1, l, r);
    }
  }
  return 0;
}