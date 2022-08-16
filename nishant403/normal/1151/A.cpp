#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
 ll n,k,i,j,a=0;
 string s;
 string aa="ACTG";   
    cin >> n;
    cin >> s;
    
 ll ans=999999999;   
 ll temp;
    
    f(i,n-4+1)
    {
        temp=0;
       f(j,4) temp+=min(abs( (s[i+j]-aa[j]+26)%26 ),abs( (aa[j]-s[i+j]+26)%26));
        ans=min(ans,temp);
    }
    cout << ans ;
}