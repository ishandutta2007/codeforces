#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define INFI 9e18
using namespace std;

int main(){
    ll n,m,cur,sum=0;
    cin>>n;
    vi p (n);
    for(int i=0;i<n;i++) cin>>p[i];
    sort(all(p));
    for(int i=0;i<n;i++) sum+=p[i];
    cin >>m;
    vi q (m);
    for(int i=0;i<m;i++) {
        cin >>q[i];
    }
    for(int i=0;i<m;i++) {
        cout << (sum-p[n-q[i]])<<endl;
    }
}