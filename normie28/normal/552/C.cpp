
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
int inf_int=2e9;
ll inf_ll=2e18;
typedef pair<int,int> pii;
#define pb push_back
const double pi=3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz size()
template<typename T,typename T1>
void prin(vector<pair<T,T1> >& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i].fi<<" "<<a[i].se<<"\n";
    }
}
template<typename T>
void prin(vector<T>& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i];
        if(i<a.size()-1)
            cout<<" ";
        else
            cout <<"\n";
    }
}
template<typename T>
void prin(set<T>& a)
{
    for(auto it=a.begin();it!=a.end();it++)
    {
        cout << *it<<" ";
    }
}
template<typename T>
void prin_new_line(vector<T>& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i]<<"\n";
    }
}
template<typename T,typename T1>
void prin_new_line(vector<pair<T,T1> >& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i].fi<<" "<<a[i].se<<"\n";
    }
}
 
int sum_vec(vector<int>& a)
{
    int s=0;
    for(int i=0;i<a.size();i++)
    {
        s+=a[i];
    }
    return s;
}
template<typename T>
T max(vector<T>& a)
{
    T ans=a[0];
    for(int i=1;i<a.size();i++)
    {
        ans=max(ans,a[i]);
    }
    return ans;
}
template<typename T>
T min(vector<T>& a)
{
    T ans=a[0];
    for(int i=1;i<a.size();i++)
    {
        ans=min(ans,a[i]);
    }
    return ans;
}
template<typename T>
T min(T a,T b,T c)
{
    return min(a,min(b,c));
}
template<typename T>
T max(T a,T b,T c)
{
    return max(a,max(b,c));
}
 
double s_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return abs(((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2);
}
bool overflow(ll a,ll b)
{
    if(a*b/b!=a)
        return true;
    return false;
}
#define x1 gfgs
#define y1 asd
bool debug=0;
const int maxn=600;
 
void solve()
{
    int w,m;
    cin >> w >> m;
    int z=0;vector<int> a;
    while(m)
    {
        a.pb(m%w);
        m=m/w;
    }
    for(int i=0;i<a.sz;i++)
    {
        if(i>110)
        {
 
            cout << "NO";
            return;
        }
        if(a[i]==1 || a[i]==0)
        {
            continue;
        }
        else
        {
            if(i==a.sz-1)
            {
                a.pb(1);
            }
            else
            {
                a[i+1]++;
            }
            a[i]=a[i]-w;
            if(a[i]!=-1 && a[i]!=0)
            {
                cout << "NO";
                return;
            }
 
        }
    }
    cout << "YES";
 
}
 
 
 
#define FILE "humble"
int main()
{
       if(!debug)
       {
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
       }
        int t=1;
        while(t--)
            solve();
        return 0;
}