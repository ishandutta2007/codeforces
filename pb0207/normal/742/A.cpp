#include <iostream>   
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <algorithm>  
#include <climits>  
#include <cstring>  
#include <string>  
#include <set>  
#include <map>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <list>  
#define rep(i,m,n) for(i=m;i<=n;i++)  
#define rsp(it,s) for(set<int>::iterator it=s.begin();it!=s.end();it++)  
const int inf_int = 2e9;  
const long long inf_ll = 2e18;  
#define inf_add 0x3f3f3f3f  
#define mod 1000000007  
#define vi vector<int>  
#define pb push_back  
#define mp make_pair  
#define fi first  
#define se second  
#define pi acos(-1.0)  
#define pii pair<int,int>  
#define Lson L, mid, rt<<1  
#define Rson mid+1, R, rt<<1|1  
const int maxn=5e2+10;  
using namespace std;  
typedef  long long ll;  
typedef  unsigned long long  ull;   
inline int read(){int ra,fh;char rx;rx=getchar(),ra=0,fh=1;  
while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();if(rx=='-')  
fh=-1,rx=getchar();while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,  
rx=getchar();return ra*fh;}  
//#pragma comment(linker, "/STACK:102400000,102400000")  
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}  
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}  
  
ll n;   
int a[4]={6,8,4,2};  
int main()  
{  
    cin >> n;   
    if(n==0)  
    {  
        cout << "1" <<endl;   
        return 0;  
    }  
          
    cout << a[n%4]<<endl;  
      
    return 0;   
}