#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;


main(){
    string s;cin>>s;
    int n=s.size();
    int left=0,right=n-1;
    vector<char> ans;
    while(1){
        int t[3]={};
        if(left>=right){
            for(auto e:ans)cout<<e;
            rep(i,ans.size()){
                cout<<ans[ans.size()-1-i];
            }
            return 0;
        }
        else if(right-left<=2){
            for(auto e:ans)cout<<e;
            cout<<s[left];
            rep(i,ans.size()){
                cout<<ans[ans.size()-1-i];
            }
            return 0;
        }
        t[(int)(s[left]-'a')]++;
        t[(int)(s[++left]-'a')]++;
        t[(int)(s[right--]-'a')]++;
        t[(int)(s[right]-'a')]++;
        left++;right--;
        //rep(i,3)cout<<t[i];
        rep(i,3){
            if(t[i]>=2){ans.pb((char)('a'+i));break;}
        }
    }
}