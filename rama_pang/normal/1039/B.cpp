#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll N,K,Q;
    cin >> N >> K;
    ll le=1;
    ll ri=N;
    string j;
    while (true){
        if (ri-le+1<=4*K+5){
            ll r=rand()%(4*K +7);
            cout << min(le+r, N) << " " << min(le+r,N) << endl;
            cin>>j;
            if (j=="Yes"){
                return 0;
            } else{
                le= max(le-K, 1ll);
                ri=min(ri+K,N);
                continue;
            }
        }
        ll mid=(le+ri)/2;
        cout << le << " " << mid << endl;
        cin>>j;
        if (j=="Yes"){
            le=max(1ll, le-K);
            ri= min(mid+K, N);
        } else{
            le= max(mid-K, 1ll);
            ri=min(ri+K,N);
        }
    }
}