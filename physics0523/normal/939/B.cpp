#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  long long id,num,res=-1;
  for(int i=1;i<=k;i++){
    long long v;
    cin >> v;
    long long cn=(n/v);
    if(res<cn*v){
      id=i;num=cn;res=cn*v;
    }
  }
  cout << id << ' ' << num << '\n';
  return 0;
}