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
int arr[N];

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

int an;

void add(int x){
  if(x < N){
    if(aa[x] == x)an --;
    aa[x] ++ ;
    if(aa[x] == x)an ++;
  }
}

void rem(int x){
  if(x < N){
    if(aa[x] == x) an -- ;
    aa[x] -- ;
    if(aa[x] == x) an ++ ;
  }
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  for(int i = 0;i < n;i ++ ){
    cin >> arr[i];
  }
  Query Q[q];
  for(int i = 0;i < q;i ++ ){
    cin >> Q[i].left_bound >> Q[i].right_bound;
    Q[i].left_bound -- ;
    Q[i].right_bound --;
    Q[i].index = i;
  }
  int as[q];
  sort(Q, Q + q);
  int lf = 0, rf = -1;
  int cl, cr;
  for(int i = 0;i < q;i ++ ){
    cl = Q[i].left_bound;
    cr = Q[i].right_bound;
    if(cl == cr){
      if(arr[cl] == 1)as[Q[i].index] = 1;
      else as[Q[i].index] = 0;
      continue;
    }
    while(lf < cl){
      rem(arr[lf]);
      lf ++ ;
    }
    while(lf > cl){
      lf -- ;
      add(arr[lf]);
    }
    while(rf < cr){
      rf ++ ;
      add(arr[rf]);
    }
    while(rf > cr){
      rem(arr[rf]);
      rf -- ;
    }
    as[Q[i].index] = an;
  }
  for(int i = 0; i <q;i ++ )
    cout << as[i] << "\n";
  return 0;
}