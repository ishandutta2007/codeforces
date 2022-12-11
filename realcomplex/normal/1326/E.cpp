#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
int pos[N];

struct Node{
  int value;
  int lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
  T[node].value += T[node].lazy;
  if(cl != cr){
    T[node*2].lazy+=T[node].lazy;
    T[node*2+1].lazy+=T[node].lazy;
  }
  T[node].lazy=0;
}

void upd(int node, int cl, int cr, int tl, int tr, int v){ 
  push(node,cl,cr);
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    T[node].lazy += v;
    push(node, cl, cr);
    return;
  }
  int mid = (cl + cr)/2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
  T[node].value = min(T[node * 2].value, T[node * 2 + 1].value);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    pos[a]=i;
  }
  int ans = n;
  cout << n << " ";
  for(int i = 1; i < n; i ++ ){
    cin >> a;
    upd(1, 1, n, 1, a, +1);
    while(1){
      upd(1, 1, n, 1, pos[ans], -1);
      if(T[1].value < 0){
        upd(1, 1, n, 1, pos[ans], +1);
        break;
      }
      ans--;
    }
    cout << ans << " ";
  }
  return 0;
}