#include<bits/stdc++.h>

using namespace std;

void resout(vector<int> &ra, vector<int> &rb){
  int q=ra.size();
  cout << q << '\n';
  for(int i=0;i<q;i++){cout << ra[i] << ' ' << rb[i] << '\n';}
  return;
}

int n;

void uni(int st,int lg,int fl,vector<int> &ra, vector<int> &rb){
  if(lg<1){return;}
  if(fl&1){uni(st,lg/2,3,ra,rb);}
  if(fl&2){uni(st+lg,lg/2,3,ra,rb);}
  for(int i=0;i<lg;i++){
    ra.push_back(st+i);
    rb.push_back(st+lg+i);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  if(n<=2){puts("0");return 0;}
  if(n==3){puts("1");puts("1 2");return 0;}
  vector<int> ra,rb;
  int k=1;
  while(1){
    k*=2;
    if(k>n){k/=4;break;}
  }
  uni(1,k,3,ra,rb);
  uni((n+1)-2*k,k,3,ra,rb);
  resout(ra,rb);
  return 0;
}