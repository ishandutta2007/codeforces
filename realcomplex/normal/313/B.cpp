#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
const int BL = 330;
int aa[N];

struct Query{
  int left_bound;
  int right_bound;
  int index;
  bool operator< (const Query &a){
    if(left_bound/BL == a.left_bound/BL)
      return right_bound < a.right_bound;
    else
      return left_bound/BL < a.left_bound/BL;
  }
};

int main(){
  fastIO;
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 0; i < n-1;i ++ ){
    if(s[i] == s[i + 1])
      aa[i] = 1;
  }
  int q;
  cin >> q;
  Query Q[q];
  for(int i = 0;i < q;i ++ ){
    cin >> Q[i].left_bound >> Q[i].right_bound;
    Q[i].left_bound -- ;
    Q[i].right_bound -= 2;
    Q[i].index = i;
  }
  int as[q];
  sort(Q, Q + q);
  int ans = 0;
  int lf = 0, rf = -1;
  int cl, cr;
  for(int i = 0;i < q;i ++ ){
    cl = Q[i].left_bound;
    cr = Q[i].right_bound;
    while(lf < cl){
      ans -= aa[lf];
      lf ++ ;
    }
    while(lf > cl){
      lf -- ;
      ans += aa[lf];
    }
    while(rf < cr){
      rf ++ ;
      ans += aa[rf];
    }
    while(rf > cr){
      ans -= aa[rf];
      rf -- ;
    }
    as[Q[i].index] = ans;
  }
  for(int i = 0; i <q;i ++ )
    cout << as[i] << "\n";
  return 0;
}