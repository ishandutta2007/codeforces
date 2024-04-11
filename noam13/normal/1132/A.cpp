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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a==0 && c>0) cout << 0 <<endl;
    else{
        if (a!=d) cout << 0 <<endl;
        else cout << 1 <<endl;
    }

}