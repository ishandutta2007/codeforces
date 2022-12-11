#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main() {

    ll n,x,y;
    cin >> n >> x >> y;
    ll sum = 0;
    ll rem = y;
    for(int i = 0;i<n-1;i++){
        sum++;
        rem--;
    }
    if(rem <= 0 || sum + rem*rem < x){
        cout << -1;
    }
    else{
        for(int i = 0;i<n-1;i++){
            cout << 1 << "\n";
        }
        cout << rem;
    }
	return 0;
}