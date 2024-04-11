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
    int a,b;
    cin >> a >> b;
    b=abs(b-a);
    int r=0;
    r=b/5;
    b%=5;
    if(b==1){r++;}
    if(b==2){r++;}
    if(b==3){r+=2;}
    if(b==4){r+=2;}
    cout << r << '\n';
  }
}