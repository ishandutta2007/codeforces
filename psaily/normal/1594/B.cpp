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

int T;
ll n,k;

int main() {
    cin>>T;
    while (T--) {
        cin>>n>>k; 
        ll bas=1,res=0;
        
        while (k) {
            if (k&1) res=(res+bas)%mod;
            bas=bas*n%mod;
            k>>=1;
        }
        printf("%lld\n",res);
    }
    
    return 0;   
}