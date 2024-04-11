// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int s[7];
  for(int i=1; i<7; i++){
      cin >> s[i];
  }
  cout << "3" << endl;
  
  cout << s[1]-s[3]+s[5] << " " << s[2]-s[4]+s[6] << endl;
  cout << s[1]+s[3]-s[5] << " " << s[2]+s[4]-s[6] << endl;
  cout << -s[1]+s[3]+s[5] << " " << -s[2]+s[4]+s[6] << endl;

}