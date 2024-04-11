#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<int> p;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){p.push_back(i);}
    }
    int ord=(p.size())*11;
    if(p.size()>=2){
      if((n-1-p[p.size()-1])<=k){ord-=10;k-=(n-1-p[p.size()-1]);}
      if(p[0]<=k){ord--;k-=p[0];}
    }
    else if(p.size()==1){
      if((n-1-p[0])<=k){ord-=10;}
      else if(p[0]<=k){ord--;}
    }
    cout << ord << '\n';
  }
}