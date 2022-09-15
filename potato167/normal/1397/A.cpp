#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    vector<int> p(26);
    for(int j=0;j<a;j++){
      string S;
      cin>>S;
      int L=S.size();
      for(int k=0;k<L;k++){
        p[S[k]-'a']++;
      }
    }
    int Z=1;
    for(int j=0;j<26;j++){
      if(p[j]%a!=0){
        Z=0;
      }
    }
    if(Z){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}