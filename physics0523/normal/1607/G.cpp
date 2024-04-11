#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n),b(n);
    long long sa=0,sb=0;
    for(int i=0;i<n;i++){
      cin >> a[i] >> b[i];
      sa+=a[i];
      sb+=b[i];
    }
    long long aim=(sa+sb-n*m)/2;
    long long perm=sa-aim;
    vector<long long> ra(n,0);
    for(int i=0;i<n;i++){
      ra[i]=max(0ll,m-b[i]);
      perm-=ra[i];
    }
    perm=max(0ll,perm);
    for(int i=0;i<n;i++){
      long long am=min(m,a[i])-ra[i];
      if(perm<=am){
        ra[i]+=perm;
        perm=0;
      }
      else{
        ra[i]+=am;
        perm-=am;
      }
    }
    long long res=0;
    for(int i=0;i<n;i++){
      res+=(a[i]-ra[i]);
      res-=(b[i]-(m-ra[i]));
    }
    cout << max(res,-res) << '\n';
    for(int i=0;i<n;i++){
      cout << ra[i] << ' ' << m-ra[i] << '\n';
    }
  }
  return 0;
}