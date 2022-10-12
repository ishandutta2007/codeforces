#include<bits/stdc++.h>

using namespace std;

bool isperm(vector<int> a){
  sort(a.begin(),a.end());
  int n=a.size();
  for(int i=0;i<n;i++){
    if(a[i]!=(i+1)){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,sg=0;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){cin >> a[i];sg+=a[i];}
    if(n>m || n==2){cout << "-1\n";continue;}
    cout << 2*sg << '\n';
    for(int i=1;i<n;i++){cout << i << ' ' << i+1 << "\n";}
    cout << 1 << ' ' << n << "\n";
  }
}