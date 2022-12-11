#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

ll n,mid;

ll dep(ll k){
    ll t = 1;
    while((k+t)%(t*2)!=0)t*=2;
    return t;
}

ll lef(ll k,char w){
    if(w == 'L'){
        return k-(dep(k)/2);
    }
    else if(w == 'R'){
        return k+(dep(k)/2);
    }
    ll dis = dep(k);
    if(k == mid) return k;
    if((k+dis)/(dis*2)%2==0) return k-dis;
    else return k+dis;
}

void query(){
    string s;
    ll start;
    cin >> start >> s;
    for(int j = 0;j<s.size();j++){
        start = lef(start,s[j]);
    }
    cout << start << "\n";
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> n >> q;
    mid = n/2+1;
    for(int j = 0;j<q;j++)query();
    return 0;
}