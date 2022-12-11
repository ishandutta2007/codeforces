#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  int q1 = 0,q2 = 0;
  int x,y;
  for(int i = 0;i<n;i++){
    cin >> x >> y;
    if(x>0)q1++;
    else q2++;
  }
  if(q1<=1||q2<=1)
    puts("Yes");
  else
    puts("No");
  return 0;
}