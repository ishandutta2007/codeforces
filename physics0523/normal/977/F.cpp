#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  set<pair<int,int>> st;
  for(int i=0;i<n;i++){
    cin >> a[i];
    st.insert(make_pair(a[i],i));
  }

  vector<int> res,tg;
  vector<bool> fl(n,false);
	for(auto &nx : st){tg.push_back(nx.second);}

  for(int i=0;i<n;i++){
    vector<int> cr;
    int p=tg[i];
		if(fl[p]){continue;}
    while(1){
      cr.push_back(p);
      fl[p]=true;
      auto it=st.lower_bound(make_pair(a[p]+1,p));
      if(it==st.end()){break;}
      if((*it).first!=a[p]+1){break;}
      p=(*it).second;
			if(fl[p]){break;}
    }
    if(res.size()<cr.size()){res.swap(cr);}
  }

  cout << res.size() << '\n';
  for(auto &nx : res){cout << nx+1 << '\n';}
  return 0;
}