#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

	ll l1,l2,k1,k2,b;
	cin >> l1 >> l2 >> k1 >> k2 >> b;
	ll sak,beig;
	sak = max(l1,k1);
	beig = min(l2,k2);
	if(beig<sak){
        cout << 0;
	}
	else{
        ll am = (beig-sak)+1;
        if(b >= sak && b <= beig){
            am--;
        }
        cout << am;
	}
    return 0;
}