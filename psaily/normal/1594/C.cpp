// #include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
// head

const int mod=1e9+7;
const int N=3e5+50;

int T;
int n;
char op[3],str[N];

int main() {
    cin>>T;
    while (T--) {
        scanf("%d%s%s",&n,op,str+1);
        
        bool ok=0;
        
        for (int i=1;i<=n;i++) {
            bool flag=1;
            for (int j=i;j<=n;j+=i) {
                if (str[j]!=op[0]) {flag=0; break;}
            }  
            if (flag) {
                ok=1;
                if (i==1) puts("0");
                else printf("1\n%d\n",i);
                break;
            }
        }
        
        if (!ok) {
            puts("2");
            printf("%d %d\n",n,n-1);
        }
        
    }
    
    return 0;   
}