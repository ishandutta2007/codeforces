#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,r;
  cin >> n >> r;
  set<int> st;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    if(v==1){st.insert(i);}
  }
  int cov=-1,res=0;
  while(cov<(n-1)){
    int tg=cov+r;
    auto it=st.lower_bound(tg+1);
    if(it==st.begin()){res=-1;break;}
    it--;
    res++;
    int ncov=(*it)+r-1;
    if(cov>=ncov){res=-1;break;}
    cov=ncov;
  }
  cout << res << '\n';
  return 0;
}