#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int>sk;
    for(int i = 2;i<=n;i++){
        while(n % i == 0){
            sk.push_back(i);
            n /= i;
        }
    }
    if(sk.size() < k){
        cout << -1;
    }
    else{
        while(sk.size() > k){
            sk[0] = sk[0] * sk[1];
            sk.erase(sk.begin() + 1);
        }
        for(int i = 0;i<sk.size();i++){
            cout << sk[i] << " ";
        }
    }
    return 0;
}