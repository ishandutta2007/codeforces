#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n),b(n+1),pt(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[a[i]]=i;
  }
  int fv=n+100,sv=n+1000;
  for(int i=n;i>=1;i--){
    if(b[i]<fv){sv=fv;fv=b[i];}
    else if(b[i]<sv){pt[fv]++;sv=b[i];}
  }
  int rc=0,res=a[0];
  for(int i=1;i<n;i++){
    if(pt[rc]<pt[i]){
      rc=i;
      res=a[i];
    }
    else if(pt[rc]==pt[i]){res=min(a[i],res);}
  }
  if(pt[rc]<=1){
    int rec=0;
    for(int i=0;i<n;i++){
      if(rec<a[i]){
        if(rec+1==a[i]){rec=a[i];}
        else{cout << rec+1 << '\n';return 0;}
      }
    }
    cout << 1 << '\n';
    return 0;
  }
  cout << res << '\n';
  return 0;
}