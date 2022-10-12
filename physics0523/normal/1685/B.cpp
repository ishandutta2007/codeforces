#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

pi jud(char c,int l){

  if(l%2==1){
    return {1,l/2};
  }
  else if(c=='A'){
    return {2,l/2};
  }
  else{
    return {3,l/2};
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,ab,ba;
    cin >> a >> b >> ab >> ba;
    string s;
    cin >> s;
    int l=s.size();

    int ta=a+ab+ba;
    int tb=b+ab+ba;
    for(auto &nx : s){
      if(nx=='A'){ta--;}
      else if(nx=='B'){tb--;}
    }
    if(ta!=0 || tb!=0){cout << "NO\n";continue;}

    int free=0;
    priority_queue<int,vector<int>,greater<int>> abab,baba;
    int st=0;
    for(int i=1;i<=l;i++){
      if(i==l || s[i-1]==s[i]){
        pi cur=jud(s[st],i-st);
        // cout << cur.first << ' ' << cur.second << '\n';
        if(cur.first==1){free+=cur.second;}
        else if(cur.first==2){abab.push(cur.second);}
        else{baba.push(cur.second);}
        st=i;
      }
    }

    while(!abab.empty() && ab>0){
      int od=abab.top();abab.pop();
      int del=min(od,ab);
      od-=del;ab-=del;
      if(od>0){abab.push(od);}
    }

    while(!baba.empty() && ba>0){
      int od=baba.top();baba.pop();
      int del=min(od,ba);
      od-=del;ba-=del;
      if(od>0){baba.push(od);}
    }

    if(ab+ba<=free){cout << "YES\n";continue;}
    else if(ab<=0){
      ba-=free;
      while(!abab.empty() && ba>0){
        int od=abab.top();abab.pop();
        if(od>0){od--;}
        int del=min(od,ba);
        od-=del;ba-=del;
        if(od>0){abab.push(od);}
      }
      if(ba<=0){cout << "YES\n";}else{cout << "NO\n";}
      continue;
    }
    else if(ba<=0){
      ab-=free;
      while(!baba.empty() && ab>0){
        int od=baba.top();baba.pop();
        if(od>0){od--;}
        int del=min(od,ab);
        od-=del;ab-=del;
        if(od>0){baba.push(od);}
      }
      if(ab<=0){cout << "YES\n";}else{cout << "NO\n";}
    }
    else{cout << "NO\n";continue;}
  }
  return 0;
}