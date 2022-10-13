#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k,r=0;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v;
    int cnt=-1000000,amr=0;
    int fl=1;
    for(int i=0;i<n;i++){
      if(s[i]=='W'){fl=0;}
    }
    if(fl==1){
      cout << max(0,2*min(n,k)-1) << '\n';
      continue;
    }
    fl=0;
    s+='W';
    for(int i=0;i<n-1;i++){
      if(s[i]=='W' && s[i+1]=='W'){r++;}
    }
    for(int i=0;i<=n;i++){
      if(s[i]=='W'){
        if(i!=n){r++;}
        if(i==n){amr+=cnt;break;}
        if(cnt>0){v.push_back(cnt);}
        else if(cnt<0){amr=1000000+cnt;}
        cnt=0;
      }
      else{cnt++;}
    }
    sort(v.begin(),v.end());
    int l=v.size(),pt=0;
    //cout << l <<'\n';
    while(pt<l && k>0){
      //cout << v[pt] << ' ' << r << ' ' << k << '\n';
      k--;
      v[pt]--;
      r+=2;
      if(v[pt]==0){
        pt++;r++;
      }
    }
    cout << r+2*min(amr,k) << '\n';
  }
}