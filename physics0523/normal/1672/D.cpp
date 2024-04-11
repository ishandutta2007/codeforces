#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    vector<int> sa=a,sb=b;
    sort(sa.begin(),sa.end());
    sort(sb.begin(),sb.end());
    if(sa!=sb){cout << "NO\n";continue;}

    b.push_back(-1);
    vector<int> fl(n+1,0);
    vector<int> keep(n+1,0);
    bool rfl=true;
    int i=n-1,j=n-1;
    while(i>=0 && j>=0){
      if(a[i]==b[j]){
        fl[a[i]]=1;
        i--;j--;
      }
      else if(b[j]==b[j+1]){keep[b[j]]++;j--;}
      else if(keep[a[i]]>0){keep[a[i]]--;i--;}
      else{rfl=false;break;}
    }
    if(rfl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}