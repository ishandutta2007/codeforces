#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 9;
int A[N];
int B[N];
int IND[N];

bool comp(int a,int b){
  return A[a]>A[b];
}

int main(){
  int n;
  cin >> n;
  for(int i = 0;i<n;i++)cin >> A[i];
  for(int i = 0;i<n;i++)cin >> B[i];
  for(int i = 0;i<n;i++)IND[i] = i;
  sort(IND,IND+n,comp); 
  vector<int>rez;
  rez.push_back(IND[0]);
  int c = 0;
  for(int i = 1;i<n;i+=2){
    c=IND[i];
    if(i+1<n and B[IND[i+1]]>B[c])
      c=IND[i+1];
    rez.push_back(c);
  }
  cout << rez.size() << "\n";
  for(auto x : rez)
    cout << x+1 << " ";
  return 0;
}