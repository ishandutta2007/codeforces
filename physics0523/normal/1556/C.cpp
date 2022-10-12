#include<bits/stdc++.h>

using namespace std;

using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;

  long long res=0;
  long long v;
  stack<pl> st;
  for(int i=0;i<n;i++){
    cin >> v;
    if(i%2==0){
      if(st.empty()){st.push({1,1});}
      st.push({v,1});
    }
    else{
      // pop 1 elem
      if(!st.empty()){
        pl od=st.top();st.pop();
        //cout << od.first << ',' << od.second << ' ' << res << '\n';
        if(od.first!=1){st.push({od.first-1,od.second});}
      }
      // pop (v-1) elem
      v--;
      while(!st.empty() && v>0){
        pl od=st.top();st.pop();
        //cout << od.first << ',' << od.second << ' ' << res << '\n';
        if(od.first>=v){
          res+=v*od.second;
          if(od.first!=v){st.push({od.first-v,od.second});}
          break;
        }
        else{
          v-=od.first;
          res+=od.first*od.second;
        }
      }
      // pop 1 elem
      if(!st.empty()){
        pl od=st.top();st.pop();
        //cout << od.first << ',' << od.second << ' ' << res << '\n';
        if(od.first!=1){
          st.push({od.first-1,od.second});
        }
        od.first=1;
        res+=od.second;
        od.second++;
        st.push({1,od.second});
      }
    }
  }
  cout << res << '\n';
  return 0;
}