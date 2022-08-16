

#include <bits/stdc++.h>
#include <ctime>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll randompower(ll n)
{
    ll x=243546541;
    for(int i=1;i<=5;i++)
    {
        x=(x*rand())%n +1;
    }
    return x;
}

int main()
{
       srand(time(NULL));
    int q=60;
    ll n,x;
    cin >> n;
    ll l=0,r=1000000000;
    ll m;
    while(r>=l)
    {
        m=(l+r)/2;
        cout << "> " << m << "\n";
       cin >> x;
       if(x==1) l=m+1;
       else r=m-1;
       q--;

       if(q==30) break;
    }

    m=l;


     vector<int> a;
     a.push_back(m);


    for(int i=1;i<=q;i++)
    {
    cout << "? " << randompower(n) << "\n";
    cin >> x;
    a.push_back(x);
    }
    
  ll ans=abs(a[1]-a[0]);
  
     for(int i=0;i<a.size();i++)
        for(int j=i+1;j<a.size();j++)
           ans=gcd(ans,abs(a[j]-a[i]));

   
    cout << "! " << m-(n-1)*ans << " " << ans << endl;
     return 0;
}