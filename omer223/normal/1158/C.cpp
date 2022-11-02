#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n;
    cin>>n;
    vector<int> nxt(n);
    foru(i,0,n)cin>>nxt[i];
    stack<int> stk;
    foru(i,0,n){
        if(stk.empty()){
            if(nxt[i]==-1||nxt[i]==n+1)nxt[i]=n+1;
            else stk.push(nxt[i]);
        }
        else{
            if(i+1==stk.top())stk.pop();
            if(!stk.empty()){
            if(nxt[i]>stk.top()){
                cout<<-1<<'\n';
                return;
            }
            else if (nxt[i]!=-1){
                if(nxt[i]!=stk.top())stk.push(nxt[i]);
            }
            else{
                nxt[i]=i+2;
            }
            }
            else{
                if(nxt[i]==-1||nxt[i]==n+1)nxt[i]=n+1;
                else stk.push(nxt[i]);
            }
        }
    }
    vector<int> p(n);
    vector<vector<int>> adj(n);
    int crhgh=n;
    foru(i,0,n){
        if(nxt[i]==n+1)p[i]=crhgh--;
        else adj[nxt[i]-1].pb(i);
    }
    ford(i,n-1,0){
        for (int x : adj[i])p[x]=crhgh--;
    }
    foru(i,0,n){
        cout<<p[i]<<' ';
    }
    cout<<'\n';
    
}

int main() {
    fast;
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}