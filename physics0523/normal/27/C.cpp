#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+2);
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  vector<int> lmin(n+2);
  vector<int> lmax(n+2);
  lmin[1]=1;
  lmax[1]=1;
  for(int i=2;i<=n;i++){
    if(a[lmin[i-1]]>a[i]){lmin[i]=i;}
    else{lmin[i]=lmin[i-1];}

    if(a[lmax[i-1]]<a[i]){lmax[i]=i;}
    else{lmax[i]=lmax[i-1];}
  }

  vector<int> rmin(n+2);
  vector<int> rmax(n+2);
  rmin[n]=n;
  rmax[n]=n;
  for(int i=n-1;i>=1;i--){
    if(a[rmin[i+1]]>a[i]){rmin[i]=i;}
    else{rmin[i]=rmin[i+1];}

    if(a[rmax[i+1]]<a[i]){rmax[i]=i;}
    else{rmax[i]=rmax[i+1];}
  }

  for(int i=2;i<n;i++){
    if(a[lmin[i-1]]<a[i] && a[i]>a[rmin[i+1]]){
      cout << "3\n";
      cout << lmin[i-1] << " " << i << " " << rmin[i+1] << "\n";
      return 0;
    }
    if(a[lmax[i-1]]>a[i] && a[i]<a[rmax[i+1]]){
      cout << "3\n";
      cout << lmax[i-1] << " " << i << " " << rmax[i+1] << "\n";
      return 0;
    }
  }
  cout << "0\n";
  return 0;
}