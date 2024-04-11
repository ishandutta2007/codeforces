#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int main()
{
   int n;cin>>n;
   for (int i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   vector<int>u;
   vector<int>v;
   for (int i=0;i<(n-2);i++){
       if (a[i]==a[i+1] && a[i+1]==a[i+2]){
          cout<<"NO";
          return 0;
       }
   }
   u.push_back(a[0]);
   for (int i=1;i<n;i++){
     if (a[i]==a[i-1]) v.push_back(a[i]);
     else u.push_back(a[i]);
   }
   reverse(v.begin(),v.end());
   cout<<"YES"<<endl;
   cout<<u.size()<<endl;
   for (int i=0;i<u.size();i++) cout<<u[i]<<" ";
   cout<<endl<<v.size()<<endl;
   for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/