#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head

const int N=2e5+5;
const int mod=998244353;
int n;
char s[N];

void solve() {
    scanf("%d%s",&n,s);
    int m=strlen(s);
    int tt=0;
    rep(i,0,m) {
        if (s[i]=='D') tt|=1;
        else tt|=2;
    }
    if (tt!=3) {
        printf("%d\n",n);
        return; 
    }
    
    int p=0,r=n,c=n;
    rep(i,0,m) if (s[p=i]!=s[0]) break;
    if (s[0]=='D') r-=p;
    else c-=p;
    ll ans=p+1ll*r*c;
    int cx=0,cy=0;
    per(i,m,p) {
        if (s[i]=='R') {
            cy++;
            ans-=cx;
        }else {
            cx++;
            ans-=cy;
        }
    }
    printf("%lld\n",ans);
}

int main() {
    int _;
    for (cin>>_;_;_--) {
        solve();
    }
    
    return 0;    
}