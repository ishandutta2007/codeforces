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
    vector<long long> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    long long ap=0,bp=0;
    for(int i=0;i<n;i++){
      if(i%2==0 && a[i]%2==0){ap+=a[i];}
      if(i%2==1 && a[i]%2==1){bp+=a[i];}
    }
    if(ap>bp){cout << "Alice\n";}
    else if(ap<bp){cout << "Bob\n";}
    else{cout << "Tie\n";}
  }
  return 0;
}