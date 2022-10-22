#include <bits/stdc++.h>
//#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,long long>
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;


int main()
{
    cout << fixed << showpoint << setprecision(15);
    int k,v,n=1500;
    vi ans (n,1);
    cin >> k;
    k++;
    ans[0]=-1;
    for(int i=1;k>0;i++){
        v=(k>1e6-1?1e6-1:k);
        ans[i]+=v;
        k-=v;
    }
    cout << n <<endl;
    for(int i=0;i<n;i++){
        cout <<ans[i]<< (i<n?" ":"");
    }
    return 0;
}