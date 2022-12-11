#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define IMAX INT_MAX
#define IMIN INT_MIN

const ld PI = acos(-1);
const ll MOD = ll(1e9) + 7;

ll ab(ll k){
    if(k<0)return k*-1;
    else return k;
}

int main(){
    //freopen("in.txt","r",stdin);
    ll st,q,l;
    int n;
    cin >> st >> q >> l >> n;
    set<ll>bad;
    ll k;
    for(int i = 0;i<n;i++){
        cin >> k;
        bad.insert(k);
    }
    if(q==0){
        if(ab(st)>l){
            cout << 0 << "\n";
            return 0;
        }
        if(bad.count(0LL)==0){
        	cout << "inf\n";
        	return 0;
        }
        if(bad.count(st)){
        	cout << 0 << "\n";
        	return 0;
        }
        cout << 1 << "\n";
	return 0;
    }
    ll v = 1;
    int rem = 0;
    for(int j = 1;j<(int)2e6;j++){
        if(ab(v*st)>l){
            cout << j-rem-1 << "\n";
            return 0;
        }
        if(bad.count(v*st))rem++;
        v*=q;
    }
    if(rem>(int)1500000){
        cout << 0 << "\n";
    }
    else{
        cout << "inf\n";
    }
    return 0;
}