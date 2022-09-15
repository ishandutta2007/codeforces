#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int x[1001];
int y[1001];
set<pair<pair<int,int>,int> >st;
map<pair<int,int>,int>used;
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            int a=y[i]-y[j];
            int b=x[i]-x[j];
            ll c=1ll*a*x[i]-1ll*b*y[i];
            ll g=__gcd(a,b);
            g=__gcd(g*1ll,c);
            a/=g;
            b/=g;
            c/=g;
            if (a<0 ||(a==0 && b<0)){
                a=-a;
                b=-b;
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
            //cout<<endl;
            st.insert({{a,b},c});
        }
    }
    vector<pair<int,int> >v;
    for (auto i:st){
        v.push_back(i.first);
    }
    ll res=0ll;
    for (auto i:v){
        res+=used[i]*1ll;
        used[i]++;
    }
    cout<<1ll*(ll)v.size()*((ll)v.size()-1ll)/2ll-res;
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4