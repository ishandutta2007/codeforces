#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool p(string s){
     string s1=s;
     reverse(s1.begin(),s1.end());
     if (s==s1) return 1;
     return 0;
}
int main()
{
    ll n;cin>>n;
    pair<ll,ll> a[n];
    for (int i=0;i<n;i++) {
            cin>>a[i].first;
            a[i].second=i;
    }
    sort(a,a+n);
    int i=0;
    int k=1;
    ll b[n];
    while (i<n){
        ll x=i;
        i+=n-a[i].first;
        //cout<<i<<endl;
        if (i>n){
            cout<<"Impossible";
            return 0;
        }
        if (a[i-1].first!=a[x].first){
            cout<<"Impossible";
            return 0;
        }
        for (int j=x;j<i;j++){
            b[a[j].second]=k;

        }
        k++;
    }
    cout<<"Possible"<<endl;
    for (int i=0;i<n;i++) cout<<b[i]<<" ";

}