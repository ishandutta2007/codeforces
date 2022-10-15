#include <bits/stdc++.h>
using namespace std;
int main(){
int i,j,n;
cin>>n;
int a[n];
map<int,int> m;
for(i=0;i<n;i++) cin>>a[i];
for(i=0;i<n;i++) {
        cin>>j;
        m[j]++;
}
map<int,int> ::iterator it;
for(i=0;i<n;i++){
    it=m.lower_bound(n-a[i]);
    if(it!=m.end()&&(it->first+a[i])%n<(m.begin()->first+a[i])%n){
        it->second--;
      cout<<(it->first+a[i])%n;
      if(it->second==0) m.erase(it);
    }
    else {
         m.begin()->second--;
      cout<<(m.begin()->first+a[i])%n;
      if(m.begin()->second==0) m.erase(m.begin());
    }
cout<<" ";
}
}