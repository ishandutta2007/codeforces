#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

ll f(ll sk){
    return ((sk*(sk-1))/2)+sk;
}

int main(){

    int n;
    cin >> n;
    ll num;
    ll val = 0;
    ll mnius = 1;
    for(int i = 0;i<n;i++){
        cin >> num;
        val = f(num);
        mnius = 1;
        while(mnius<=num){
            val -= (mnius*2);
            mnius*=2;
        }
        cout << val << "\n";
    }
    return 0;
}