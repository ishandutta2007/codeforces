#include<bits/stdc++.h>

using namespace std;

int main(){
  int q;
  cin >> q;
  while(q>0){
    q--;
    string s,t;
    cin >> s >> t;
    int sl=s.size(),tl=t.size();
    bool isok=false;
    for(int i=0;i<sl;i++){
      for(int j=i;j<sl;j++){
        string cur;
        for(int k=i;k<=j;k++){cur.push_back(s[k]);}
        for(int k=j-1;k>=0 && cur.size()<tl;k--){cur.push_back(s[k]);}
        if(cur==t){isok=true;}
      }
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
}