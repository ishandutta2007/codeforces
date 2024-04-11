#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define db(x) cout << "==========>> " << #x << " is " << x << endl
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i,j) FOR(i,0,j,1)
#define RREP(i,j) RFOR(i,j,0,1)
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define all(cont) cont.begin(), cont.end()
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
using namespace std;
ll N,total,arr,total2,BIT[1000005],pref[1000005];
string s;
int main (){

    cin>>s;
    vector<ll> q, rep;
    ll banyak=0;
    ll cnt=0;
    rep.PB(0);
    for (int i=1; i<=s.size(); i++){
        if (s[i-1]!='v'){
            pref[i]= (cnt==0)? 0:cnt-1;
            rep.PB(cnt-1);
            cnt=0;
            q.PB(i);
        } else{
            cnt++;
        }
    }
    if (cnt>0){
        pref[s.size()]=cnt-1;
    }
    for (int i=1; i<=s.size(); i++){
        pref[i]+=pref[i-1];
    }
    ll total=0;
    for (int i=0; i<q.size(); i++){
        // db(q[i]);
        // cout << pref[q[i]] << " " <<pref[s.size()] << endl;
        total+= (pref[q[i]])*(pref[s.size()]-pref[q[i]]);
        // cout << total << endl;
    }
    cout << total << endl;
}