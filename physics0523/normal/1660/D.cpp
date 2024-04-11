#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

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
    for(auto &nx : a){cin >> nx;}
    int l=0,r=-1,res=0;
    int h=0,neg=0;
    vector<int> st(2,-1);
    vector<int> sh(2);
    st[0]=0;sh[0]=0;
    for(int i=0;i<n;i++){
      if(a[i]==0){
        st[0]=-1;st[1]=-1;
        sh[0]=0;sh[1]=0;
        h=0;neg=0;
      }
      if(a[i]<0){neg++;}
      if(a[i]==2 || a[i]==-2){h++;}
      if(st[neg%2]==-1){
        st[neg%2]=i+1;
        sh[neg%2]=h;
      }
      else if(res<(h-sh[neg%2])){
        res=(h-sh[neg%2]);
        l=st[neg%2];r=i;
      }
    }
    cout << l << ' ' << (n-1)-r << '\n';
  }
  return 0;
}