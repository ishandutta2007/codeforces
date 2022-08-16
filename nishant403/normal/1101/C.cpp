#include <bits/stdc++.h>
using namespace std;

bool cmp(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    if(get<0>(a)==get<0>(b))
    return (get<1>(a) < get<1>(b)); 

    return (get<0>(a) < get<0>(b));
} 
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);


int t;
cin >> t;
while(t--)
{
    int n,i,j;
    cin >> n;
 vector< tuple <int,int,int> > a;
 
 int p,q;
 for(i=0;i<n;i++) 
 {
     cin >> p >> q;
    a.push_back(make_tuple(p,q,i));
 }
 sort(a.begin(),a.end(),cmp);
 
 int fs,fe,ss=-1,se=-1;
 int ans[n]={0};
 
 fs=get<0>(a[0]);
 fe=get<1>(a[0]);
 int key=1;
 ans[get<2>(a[0])]=1;
 for(i=1;i<n;i++)
 {
    if( (fs <=get<0>(a[i]) && get<0>(a[i]) <=fe) || (fs <=get<1>(a[i]) && get<1>(a[i]) <=fe ) )
    {
        fs=min(get<0>(a[i]),fs);
        fe=max(get<1>(a[i]),fe);
        ans[get<2>(a[i])]=1;
    }
    else
    {
        key=0;
     ans[get<2>(a[i])]=2;   
    }
     
 }
 
 if(key==1) cout << "-1\n";
 else{
      for(i=0;i<n;i++)
 cout << ans[i] << " ";
 cout << "\n";
 
 
 }
}
return 0;
}