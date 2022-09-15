#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(time(nullptr));

int32_t main()
{
    uniform_int_distribution<int> int_dist(0, 1000000);
    mt19937 rng;
    rng.seed(clock());
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;cin>>q;
    while (q--){
        int n;cin>>n;
        vector<int>v(n,0);
        for (int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int>a;
        a.push_back(v[0]);
        for (int i=1;i<n;i++){
            if (v[i]!=v[i-1]) a.push_back(v[i]);
        }
        int k=(int)a.size();
        int res=a[0];
        for (int i=0;i<min(k,100);i++){
            for (int j=i+1;j<min(k,100);j++){
                if (a[i]%a[j]) res=max(res,a[i]+a[j]);
                for (int t=j+1;t<min(k,100);t++){
                    if (a[i]%a[j] && a[i]%a[t] && a[j]%a[t]){
                        res=max(res,a[i]+a[j]+a[t]);
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}