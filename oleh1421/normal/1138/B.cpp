#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c[100001];
int a[100001];

int main()
{
   int n;cin>>n;
   string s;cin>>s;
   for (int i=0;i<s.size();i++){
       c[i+1]=int(s[i])-int('0');
   }
   cin>>s;
   int sum=0;
   for (int i=0;i<s.size();i++){
       a[i+1]=int(s[i])-int('0');
       sum+=a[i+1];
   }
   vector<pair<int,int> >v;
   for (int i=1;i<=n;i++){
       v.push_back({a[i]+c[i],i});
   }
   sort(v.begin(),v.end());
   int pos0=-1;
   for (int i=0;i<n;i++){
       if (v[i].first==0) pos0=i;
   }
   int pos1=pos0;
   for (int i=0;i<n;i++){
       if (v[i].first==1) pos1=i;
   }
   //cout<<pos0<<" "<<pos1<<endl;
   for (int i=pos1;i<n;i++){
        for (int j=pos0;j<=pos1;j++){
            int t=(n/2)-i-j+pos1+pos0;
           // cout<<i<<" "<<j<<" "<<t<<" "<<endl;
            if (t<0) continue;
            if (t>pos0+1) continue;

            int sum1=(i-pos1)*2+(j-pos0);
            if (sum1==sum){
                for (int k=0;k<t;k++) cout<<v[k].second<<" ";
                for (int k=pos0+1;k<=j;k++) cout<<v[k].second<<" ";
                for (int k=pos1+1;k<=i;k++) cout<<v[k].second<<" ";
                return 0;
            }
        }
   }
   cout<<-1;
   return 0;
}

/*
6
001111
001111
*/