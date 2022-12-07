#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,h,a,b,k;
    cin>>n>>h>>a>>b>>k;
    
    while(k>0)
    {

        k--;
        ll ta,fa,tb,fb;
        cin>>ta>>fa>>tb>>fb;

        ll dif = ta-tb;
        if(dif<0)
            dif *=-1;

        
        ll min = fa>fb?fb:fa;
        ll max = fa>fb?fa:fb;

        if(dif==0)
        {
            cout<<max-min<<endl;
            continue;
        }

        ll answer = 0;
        if(max<a)
        {
            answer+= a -min;
            answer+=dif;
            answer+= a - max;
        }

        else if(min>b)
        {
            answer+= min-b;
            answer+=dif;
            answer+= max-b;
        }

        else{
            answer += dif;
            answer+= max - min;
        }
        
        cout<<answer<<endl;
        

    }
    
    return 0;
}