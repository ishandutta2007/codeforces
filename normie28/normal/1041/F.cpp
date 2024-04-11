#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
 
void TakeInputs(vector<int>& A){
  int n, y;
  scanf("%d%d", &n, &y);
  while(n--){
    int x;
    scanf("%d", &x);
    A.PB(2 * x);
  }
  sort(A.begin(), A.end());
}
 
void SplitOddEven(vector<int>& A, vector<int>& odd, vector<int>& even){
  for(auto x : A){
    if(x % 2 == 1){
      odd.PB(x);
    }
    else{
      even.PB(x);
    }
  }
  A.clear();
}
 
void DivideBy2(vector<int>& A){
  for(int i = 0; i < A.size(); ++i){
    A[i] /= 2;
  }
}
 
int Solve(vector<int>& A, vector<int>& B){
  if(A.size() == 0 || B.size() == 0 || (A.back() == 0 && B.back() == 0)){
    int res = A.size() + B.size();
    A.clear();
    B.clear();
    return res;
  }
 
  DivideBy2(A);
  DivideBy2(B);
 
  vector<int> A1, A2, B1, B2;
  SplitOddEven(A, A1, A2);
  SplitOddEven(B, B1, B2);
 
  int res = max(A1.size() + B2.size(), A2.size() + B1.size());
 
  res = max(res, max(Solve(A1, B1), Solve(A2, B2)));
 
  return res;
}
 
int main(){
  vector<int> A, B;
 
  TakeInputs(A);
  TakeInputs(B);
 
  int res = Solve(A, B);
 
  printf("%d\n", res);
 
  return 0;
}