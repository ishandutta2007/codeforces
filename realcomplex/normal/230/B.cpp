#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

bool ps(int sk){
    for(int i = 3;i<=sqrt(sk);i+=2){
        if(sk%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int>psk;
    psk.push_back(2);
    for(int i = 3;i<1000000;i+=2){
        if(ps(i) == true){
            psk.push_back(i);
        }
    }
    int n;
    ll sk;
    cin >> n;
    ll sq;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk == 1){
            cout << "NO\n";
        }
        else{
            sq = sqrt(sk);
            if(sq*sq==sk){
                if(binary_search(psk.begin(),psk.end(),sq) == false){
                   cout << "NO\n";
                }
                else{
                    cout << "YES\n";
                }
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}