#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    int turn=0,pv=0;
    int st=0,fi=n-1;
    int p=0,q=0;
    while(st<=fi){
      int cur=0;
      if(turn&1){
        while(cur<=pv && st<=fi){
          q+=a[fi];
          cur+=a[fi];
          fi--;
        }
      }
      else{
        while(cur<=pv && st<=fi){
          p+=a[st];
          cur+=a[st];
          st++;
        }
      }
      pv=cur;
      turn++;
    }
    cout << turn << ' ' << p << ' ' << q << '\n';
  }
  return 0;
}