// NOT MY CODE
// https://codeforces.com/blog/entry/91730
 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define ya          cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265359
#define printv(v)   for(auto x:v)cout<<x<<' ';cout<<endl;
#define takev(v)    for(auto &x:v)cin>>x;
inline  int         random(int a=1,int b=10)
{
    return a+rand()%(b-a+1);
}
typedef long long ll;
inline ll           lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
//#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
#define see(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
    err(it, args...);
}
#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);
 
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=2e5+9,mod=998244353;
int a[10];
int h,m,hour,mi;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    a[0]=0;
    a[1]=1;
    a[2]=5;
    a[3]=-1;
    a[4]=-1;
    a[5]=2;
    a[6]=-1;
    a[7]=-1;
    a[8]=8;
    a[9]=-1;
 
    int _;
    cin>>_;
    while(_--)
    {
 
        int i,j,k;
        hour=0,mi=0;
        char c;
        int a1,a2,b1,b2;
        cin>>h>>m;
        cin>>c;
        b2 = c-'0';
        hour += 10 * (c-'0');
 
        cin>>c;
        hour += (c-'0');
        b1 = c-'0';
        cin>>c;
        cin>>c;
        a2 = c-'0';
        mi += 10 * (c-'0');
        cin>>c;
        a1 = c-'0';
        mi += (c-'0');
 
        while(1)
        {
            //see(hour)
 
            if(a[a1]!=-1 && a[a2]!=-1 && a[b1]!=-1 && a[b2]!=-1 && (a[a1]*10+a[a2])<h && (a[b1]*10+a[b2])<m)
            {
                cout<<b2<<b1<<':'<<a2<<a1<<'\n';
                goto pp;
            }
 
            mi++;
            mi %= m;
            if(mi==0)
            {
                hour++;
                hour %= h;
            }
 
            a1 = mi%10;
            int t=mi;
            t/=10;
            a2 = t;
 
            b1 = hour%10;
            t = hour/10;
            b2 = t;
 
        }
 
        pp: ;
    }
 
    return 0;
}