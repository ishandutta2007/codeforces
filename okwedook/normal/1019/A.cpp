#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll n,m;
ll others_max(ll limit, vector<vector<ll> > parties){
    //cout<<limit<<"->";
    ll my_votes = parties[1].size();

    ll res = 0;
    vector<ll> left;
    for(ll i=2; i<=m; i++){
        while(parties[i].size() > limit){
            res += parties[i].back();
            parties[i].pop_back();
            my_votes++;
        }
        left.insert(left.end(), parties[i].begin(), parties[i].end());

    }
    sort(left.begin(), left.end());
    reverse(left.begin(), left.end());
    while(my_votes <= limit){
        if(left.empty()){
            //cout<<"ajaja"<<endl;
            return 3000LL*1000000000LL+1;
        }
        res += left.back();
        left.pop_back();
        my_votes++;
    }
    //cout<<res<<endl;
    return res;
}
vector<vector<ll> > parties(30001);
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;

    for(ll i=1; i<=n; i++){
        ll kire, ar;
        cin>>kire>>ar;
        parties[kire].push_back(ar);
    }
    for(int i=1; i<=m; i++){
        sort(parties[i].begin(), parties[i].end());
        reverse(parties[i].begin(), parties[i].end());
    }

    ll valasz = 3000LL*1000000000LL+1;
    for(ll i=0; i<=n; i++){
        valasz = min(valasz, others_max(i, parties));
    }
    cout<<valasz;
    return 0;
}