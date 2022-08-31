#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
  long long  int n,k,m;
    cin >> n >> m >> k;
    long long int i,a[n],temp;
    vector<bool> incl(n,0);
    vector<pair<long int,long int> > mapping;
    for(i=0;i<n;i++) 
    {
        cin >> temp;
        a[i]=temp;
        mapping.push_back(make_pair(temp,i));
    }
    sort(mapping.begin(),mapping.end());
    
 long long sum=0;
    for(i=1;i<=(k*m);i++) 
    {
        sum+=mapping[n-i].first;
       incl[mapping[n-i].second]=1;
    }
    cout << sum << "\n";
  long  long int c=0;
   long long int total=0;
    for(i=0;i<n;i++)
    {
     if(incl[i]) c++;
     if(c==m)
     {
         cout << i+1 << " ";
         c=0;
         total++;
     }
     if(total==k-1) break;
    }
    
    
    return 0;
}