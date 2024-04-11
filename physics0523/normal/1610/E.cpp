#include<bits/stdc++.h>

using namespace std;

bool judge(int a,int b,int c){
  if((a+c)>=2*b){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(auto &nx : a){
      cin >> nx;
      mp[nx]++;
    }
    int res=2;
    for(int i=0;i<n;i++){
      if(i!=0 && a[i-1]==a[i]){continue;}
      int mid=i+mp[a[i]],cnt=mp[a[i]]+1;
      if(mid==n){cnt--;}
      while(mid<n){
        int st=mid+1,fi=n-1,te;
        while(st<=fi){
          te=(st+fi)/2;
          if(judge(a[i],a[mid],a[te])){fi=te-1;}
          else{st=te+1;}
        }
        if(st==n){break;}
        cnt++;mid=st;
      }
      res=max(cnt,res);
    }
    cout << n-res << '\n';
  }
  return 0;
}