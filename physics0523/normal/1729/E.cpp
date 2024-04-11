#include<bits/stdc++.h>

using namespace std;

int main(){
  long long res=0,pot=0,tr=0;
  for(int i=2;tr<50 && i<=8;i++){
    for(int j=1;tr<50 && j<i;j++){
      long long qa,qb;
      cout << "? " << i << " " << j << "\n";
      fflush(stdout);
      cin >> qa;

      cout << "? " << j << " " << i << "\n";
      fflush(stdout);
      cin >> qb;
      if(qa==-1 || qb==-1){res=i-1;tr=50;}
      if(qa!=qb){pot=max(pot,qa+qb);}
      tr+=2;
    }
  }
  if(res==0){
    res=pot;
  }
  cout << "! " << res << "\n";
  fflush(stdout);
  return 0;
}