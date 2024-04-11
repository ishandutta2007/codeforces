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

class Point 
{ 
   ll x; 
   ll y; 
public: 
   Point(ll _x, ll _y) 
   { 
      x = _x; 
      y = _y; 
   } 
   ll getX() const { return x; } 
   ll getY() const { return y; } 
}; 
  
// To compare two points 
class myComparator 
{ 
public: 
    ll operator() (const Point& p1, const Point& p2) 
    { 
        return p1.getX() > p2.getX(); 
    } 
}; 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,d;
    cin>>n>>m>>d;
    map <ll,ll> answers;
    priority_queue <Point, vector<Point>, myComparator > pq;
    ll arr[n], printer[n];
    ll days[n] ;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        printer[i] = arr[i];
        days[i]=-1;
    }
    sort(arr,arr+n);

    
    ll counter = 1;
    ll i=1;
    pq.push(Point(arr[0],0));
    answers[arr[0]] = 1;
    while(i<n)
    {
        Point p = pq.top();
        ll minner = p.getX();
        ll index = p.getY();
        if(minner+d<arr[i])
        {
            pq.pop();
            pq.push(Point(arr[i],index));
            answers[arr[i]] = index+1;
            i++;
        }
        else{
            pq.push(Point(arr[i],counter));
            answers[arr[i]] = counter+1;
            i++;
            counter++;
        }
    }


    cout<<counter<<endl;
    for(ll j=0;j<n;j++)
    {
        cout<<answers[printer[j]]<<" ";
    }
    cout<<endl;
    return 0;
}