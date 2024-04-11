#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> topbit(1<<20);
  topbit[0]=-1;
  for(int i=0;i<20;i++){
    for(int j=(1<<i);j<(1<<(i+1));j++){topbit[j]=i;}
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=1;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
    }
    mp[0]++;
    vector<int> bk;
    for(auto &nx : mp){bk.push_back(nx.second);}
    sort(bk.begin(),bk.end());

    int st=bk.size(),fi=n;
    while(st<=fi){
      int te=(st+fi)/2;
      int add=te-bk.size();
      int cte=te;
      for(int i=bk.size()-1;i>=0;i--){
        add-=max(0,bk[i]-cte);
        cte--;
      }
      if(add>=0){fi=te-1;}else{st=te+1;}
    }
    cout << st << '\n';
  }
  return 0;
}