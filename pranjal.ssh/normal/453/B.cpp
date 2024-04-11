#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


const vi p={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
vi masks(60);

int memo[101][1<<16];
int a[101];

int f(int n, int mask)
{
    if(n==0)return 0;
    int &ans=memo[n][mask];
    if(ans!=-1)return ans;
    ans=f(n-1,mask)+abs(a[n]-1);
    
    FOR(i,2,58)
    {
        if((masks[i]&mask)==0)
        ans=min(ans,f(n-1,mask|masks[i])+abs(a[n]-i));
    }
    return ans;
}
void print(int n,int mask)
{
    
    if(n==0)return;
    int ans=f(n-1,mask)+abs(a[n]-1);
    int no=1;
    
    FOR(i,2,58)
    {
        if((masks[i]&mask)==0)
        {
            if(ans>f(n-1,mask|masks[i])+abs(a[n]-i))
            no=i,ans=f(n-1,mask|masks[i])+abs(a[n]-i);
        }
        
    }
    print(n-1,masks[no]|mask);
    cout<<no<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    FOR(i,2,60)
    {
        tr(p,it)
        {
            if(i%(*it)==0)
            masks[i]|=1<<(it-p.begin());
        }
    }
    int n;
    cin>>n;
    memset(memo,-1,sizeof(memo));
    
    FOR(i,1,n)cin>>a[i];
    print(n,0);
    
    
    return 0;
}