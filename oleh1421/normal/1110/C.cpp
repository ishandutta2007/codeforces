#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[1000001];
vector<int>d(ll n){
     vector<int>rez;
     while (n){
        rez.push_back(n%2);
        n/=2;
     }
     return rez;
}
int main()
{
    int q;cin>>q;
    while (q--){
        int a;cin>>a;
        vector<int>v=d(a);
        bool g=true;
        for (auto i:v){
            g=g&i;
        }
        if (g) {
            ll rez=1ll;
            for (ll i=2;i*i<=a;i++){
                if (a%i==0) {
                    rez=a/i;
                    break;
                }
            }
            cout<<rez<<endl;

        }else {
           ll rez=0;
           for (int i=0;i<v.size();i++){
                rez+=(1<<i);
           }
           cout<<rez<<endl;
        }
    }
    return 0;
}