#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pb push_back
using namespace std;
ll kons, ans, N, bit[200005];
pair<ll,ll> point[200005];
map<ll,ll> mp;
vector<ll> name;
bool way (pair<ll,ll> a, pair<ll,ll> b){return a.y<b.y or (a.y==b.y and a.x<b.x);}
void update (ll n, ll val){ if(n==0) return; for (; n<=N; n+= n&-n){bit[n]+=val;} }
ll get (ll n){ll ret=0; for(; n>0; n-= n&-n){ret+=bit[n];} return ret;}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>N;
    for (ll i=0; i<N; i++){
        cin >> point[i].x >> point[i].y;
        mp[point[i].x]++;
        if (mp[point[i].x]==1){kons++; name.pb(point[i].x);}
    }
    sort(name.begin(), name.end());
    for (ll i=0; i<name.size(); i++){update(i+1, 1);}
    sort(point, point+N, way);
    for (ll i=0; i<N; i++){
        ll loc=1, save=kons;
        vector<ll> temp;
        // ans+= (kons)*(kons+1)/2;
        // temp.pb(point[i].x);
        // cout << "=============\n";
        ll lb=lower_bound(name.begin(), name.end(), point[i].x) - name.begin() +1;
        ans += get(lb)*(get(name.size()) - get(lb-1));
        // cout << get(lb) << " " << get(name.size()) << " " << get(lb-1) << endl;
        // cout << ans << endl;
        mp[point[i].x]--;
        if (mp[point[i].x]==0) update(lb, -1);
        while (point[i+1].y==point[i].y){
            loc++;
            i++;
            ll lb2=lower_bound(name.begin(), name.end(), point[i].x) - name.begin() +1;
            ans+= (get(lb2)- get(lb))*(get(name.size()) - get(lb2-1));
            // cout << get(lb2) << " " <<get(lb) << " "<< get(name.size()) << " " << get(lb2-1) << endl;
            // cout << ans << endl;
            mp[point[i].x]--;
            lb=lb2;
            if (mp[point[i].x]==0) update(lb, -1);
        }
        // ans+= (max(save-loc, 0ll))*(loc) + (loc)*(loc+1)/2;
        // cout << ans << endl;
    }
    cout << ans << "\n";
}
/*
7
1 1
1 4
1 5
2 1
3 3
4 2
5 2
J=20

 */