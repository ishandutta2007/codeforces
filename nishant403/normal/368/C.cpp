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
 ll n,k,i,j,m,d,l,r,an=0;
string s;
    
    cin >> s;
    
    n=s.length();
    
    ll x[n+1],y[n+1],z[n+1];
    
    x[0]=y[0]=z[0]=0;
    
    f(i,n)
    {
        
       x[i+1]=x[i];
       y[i+1]=y[i];
       z[i+1]=z[i];
        
     if(s[i]=='x') x[i+1]++;   
     if(s[i]=='y') y[i+1]++;
     if(s[i]=='z') z[i+1]++;
        
    }
    
    ll q,cx,cy,cz;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        
        cx=x[r]-x[l-1];
        cy=y[r]-y[l-1];
        cz=z[r]-z[l-1];
        
     if( (abs(cx-cy)<=1 && abs(cy-cz)<=1 && abs(cz-cx)<=1)||(r-l)<2  ) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
    
}