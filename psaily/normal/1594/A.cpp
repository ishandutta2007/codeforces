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

int T;
ll n;

int main() {
    cin>>T;
    while (T--) {
        scanf("%lld",&n);
        ll a=2,b=n;
        while (b%2==0) b/=2,a*=2;
        ll x=(a+b-1)/2,y=a-x;
        
        if (x>y) swap(x,y);
        if (x==y) {
            if (x<0) x=x+1,y=-y;
            else x=-(y-1);   
        }
        printf("%lld %lld\n",x,y);
    }
    
    return 0;   
}