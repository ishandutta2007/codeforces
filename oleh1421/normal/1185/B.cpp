#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool ok(string a,string b){
     int i=0;
     int j=0;
     while (i<a.size() && j<b.size()){
        int cnt1=1;
        while (i<a.size() && a[i]==a[i+1]){
            i++;
           // cout<<i<<endl;
            cnt1++;
        }
        int cnt2=1;
        while (j<b.size() && b[j]==b[j+1]){
            j++;
            cnt2++;
        }
        if (a[i]!=b[j]) return false;
        if (cnt1>cnt2) return false;
        i++;
        j++;

      }
      if (i!=a.size() || j!=b.size()) return false;
      return true;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t;cin>>t;
   while (t--){
       string a;cin>>a;
       string b;cin>>b;
       if (ok(a,b)) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }
   return 0;
}