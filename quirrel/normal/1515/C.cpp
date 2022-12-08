#include<bits/stdc++.h>

using namespace std;
long long h[100009],ans[100009];
main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, m,x;
        cin >> n >> m >> x;
        set<pair<long long,long long> > s;
        for(long long i =1 ; i <= n; i++){
            cin >> h[i];

        }
        for(long long i = 1; i <= m; i++){
            s.insert({0,i});
        }
        for(long long i= 1; i <= n; i++){
            auto x = *s.begin();
            s.erase(s.begin());
            x.first += h[i];
            ans[i] = x.second;
            s.insert(x);
        }
        cout<<"YES"<<endl;
        for(long long i =1; i <= n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }
}