#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int used[200001];
int main()
{
   int k;cin>>k;
   string s;cin>>s;
   vector<int>a;
   for (auto i:s){
       a.push_back(i-'a');
   }
   string t;cin>>t;
   vector<int>b;
   for (auto i:t){
       b.push_back(i-'a');
   }
   vector<int>sum(k,0);
   for (int i=0;i<k;i++){
       sum[i]=a[i]+b[i];
   }
   reverse(sum.begin(),sum.end());

   for (int i=1;i<sum.size();i++){
       sum[i-1]+=(sum[i]%2)*26;
       sum[i-1]/=2;
   }
   sum[(int)sum.size()-1]/=2;
   for (int i=1;i<sum.size();i++){
       sum[i]+=sum[i-1]/26;
       sum[i-1]%=26;
   }
   reverse(sum.begin(),sum.end());
   for (auto i:sum) cout<<char(i+'a');
   return 0;
}