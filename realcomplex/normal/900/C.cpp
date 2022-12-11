#include <bits/stdc++.h>

using namespace std;

int cnt[100009];// removing i-th element increases records by cnt[i] 

int main(){
  int n;
  cin >> n;
  int l; 
  int max1=-1,max2=-1;
  for(int i = 0;i<n;i++){
    cin >> l;
    if(l>max1){
      max2=max1;
      max1=l;
      cnt[l]--;//it decreases the number of records by 1
    }
    else if(l>max2){
      max2=l;
      cnt[max1]++;
    }
  }
  int ans = -1000000,id = 0;
  for(int i = 1;i<=n;i++){
    if(cnt[i]>ans){
      ans=cnt[i];
      id=i;
    }
  }
  cout << id;
  return 0;
}