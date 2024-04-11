#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = (int)3e5 + 111;

struct SG{
  int l_bd;
  int r_bd;
  int ix;
};

bool comp(SG a, SG b){
  if(a.l_bd > b.l_bd)
    return false;
  else if(a.l_bd < b.l_bd)
    return true;
  return a.r_bd < b.r_bd;
}

SG seg[N];
int minsf[N];
int minix[N];
int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0;i < n;i ++){
    cin >> seg[i].l_bd >> seg[i].r_bd;
    seg[i].ix = i;
  }
  sort(seg,seg + n,comp);
  minsf[n] = (int)2e9;
  for(int i = n-1;i >= 0;i -- ){
    if(minsf[i + 1] < seg[i].r_bd){
      minsf[i] = minsf[i + 1];
      minix[i] = minix[i + 1];
    }
    else{
      minsf[i] = seg[i].r_bd;
      minix[i] = seg[i].ix;
    }
  }
  int prf = 0;
  int idx = -1;
  for(int i = 0;i < n - 1;i ++ ){
    if(seg[i].l_bd == seg[i + 1].l_bd){
      cout << minix[i] + 1 << " " << minix[i + 1] + 1 << "\n";
      return 0;
    }
    if(minsf[i + 1] <= seg[i].r_bd){
      cout << minix[i + 1] + 1 << " " << seg[i].ix + 1 << "\n";
      return 0;
    }
  }
  cout << "-1 -1\n";
  return 0;
}