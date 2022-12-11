#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int M = (int)1e7 + 9; // all over ze limit

int vl[M];
int lf[M], rf[M];
int root[N];
int a[N];

int cnt;

int build(int cl, int cr){
  int idx = cnt++;
  if(cl==cr)
    return idx;
  int mid = (cl + cr) >> 1;
  lf[idx] = build(cl, mid);
  rf[idx] = build(mid + 1, cr);
  return idx;
}

int upd(int node, int cl, int cr, int pos, int d){
  int idx = cnt++;
  //cout << idx << "~" << node << " | " << cl << " " << cr << "\n";
  vl[idx]=vl[node];
  lf[idx]=lf[node];
  rf[idx]=rf[node];
  vl[idx]+=d;
  if(cl==cr)
    return idx;
  int mid = (cl + cr) >> 1;
  if(mid >= pos){
    int nx = lf[idx];
    lf[idx]=upd(nx,cl,mid,pos,d);
  }
  else{
    int nx = rf[idx];
    rf[idx]=upd(nx,mid+1,cr,pos,d);
  }
  return idx;
}

int ask(int node, int cl, int cr, int k){
  if(cl==cr){
    if(k == 0 && vl[node] == 1) return cl-1;
    else return cl;
  }
  int mid = (cl + cr) / 2;
  if(vl[lf[node]] > k){
    return ask(lf[node], cl, mid, k);
  }
  else{
    return ask(rf[node], mid + 1, cr, k - vl[lf[node]]);
  }
}

int las[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ )
    las[i] = -1;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  root[n+1] = build(1, n);
  int fk;
  for(int i = n; i >= 1; i -- ){
    root[i]=root[i+1];
    if(las[a[i]] != -1){
      fk = root[i];
      root[i]=upd(fk,1,n,las[a[i]],-1);
    }
    fk=root[i];
    root[i]=upd(fk,1,n,i,+1);
    las[a[i]]=i;
  }
  int res;
  int lf;
  for(int i = 1; i <= n; i ++ ){
    lf = 1;
    res = 0;
    while(lf <= n){
      lf = ask(root[lf], 1, n, i) + 1;
      res ++ ;
    }
    cout << res << " ";
  }
  return 0;
}