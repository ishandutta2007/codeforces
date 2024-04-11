#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include <unordered_map>
#include<climits>
#include<set>
#include <iomanip>
#include<numeric>
#include<queue>
#include<stack>
#include<map> 

using namespace std;

#define ff              first
#define ss              second
#define ll              long long
#define ld              long double
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define mod             1000000007
#define inf             1e18
#define all(v)          (v).begin(),(v).end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl            "\n"
string a,b ;

bool solve(ll a1, ll a2, ll b1){
    
        bool ab = true ; 
        for(int i = 0 ; i < a2 ; i++){
            if(a[a1 + i] != b[b1 + i]){
                ab = false ; 
                break ; 
            }
        }
        //cout << a1 << " " << a2 << " " << b1 << " " << ab <<endl ; 
        if(ab){
        return ab ; 
        }
        if(a2%2){
            return ab ; 
        }
    
    ll n = a2/2 ; 
    bool k1,k2 ; 
    k1 = solve(a1,n,b1) ;
    if(k1){
        k2 = solve(a1+n,n,b1+n) ; 
        if(k2){
            return k2 ; 
        }
    } 
    k1 = solve(a1,n,b1+n) ; 
    if(k1){
        k2 = solve(a1+n,n,b1) ; 
        if(k2){
            return k2 ; 
        }
    } 
    return false ; 
    

}
int main(){

    FIO ;
    int t ;
    t =1  ;
   // cin >> t ;

    while(t--){
      cin >> a >> b;
      bool ans = solve(0,(ll)a.size(),0) ;
      if(ans){
          cout << "YES" ; 
      }
      else{
          cout << "NO" ; 
      }

    }
    return 0 ;

}