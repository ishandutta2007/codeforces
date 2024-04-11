#include <bits/stdc++.h>

using namespace std;

//check if node is a leaf
int is[1005];
//put i+1th parent in this array
int p[1005];
//count the number of leaves of children
int cnt[1005];

int main(){
  int n;
  cin >> n;
  for(int i = 1;i<=n;i++)is[i]=1;
  for(int i = 2;i<=n;i++){
    cin >> p[i];
    is[p[i]]=0;
  }
  for(int i = 2;i<=n;i++)
    cnt[p[i]]+=is[i];
  for(int j = 1;j<=n;j++){
    if(is[j]==1)continue;
    if(cnt[j]>=3)continue;
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  return 0;
}