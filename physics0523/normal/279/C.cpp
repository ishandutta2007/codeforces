#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n+1),b(n+1);
  for(int i=1;i<=n;i++){cin >> a[i];}
  set<int> le,gr;
  le.insert(n);
  le.insert(n+1);
  gr.insert(n);
  gr.insert(n+1);
  
  for(int i=1;i<=n-1;i++){
    if(a[i]>a[i+1]){le.insert(i);}
    if(a[i]<a[i+1]){gr.insert(i);}    
  }

  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;
    auto il=le.lower_bound(l);
    int p=(*il);
    auto ig=gr.lower_bound(p);
    p=(*ig);
    if(r<=p){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}