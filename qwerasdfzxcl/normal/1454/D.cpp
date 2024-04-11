#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<ll> prime;
bool primecheck[100001]={0};

int main(){
    int t;
    scanf("%d", &t);
    for (int i=2;i<100001;i++) primecheck[i]=1;
    for (ll i=2;i<100001;i++){
        ll j=2;
        if (!primecheck[i]) continue;
        while(i*j<100001){
            primecheck[i*j]=0;
            j++;
        }
        prime.push_back(i);
    }
    while(t--){
        ll n;
        scanf("%lld", &n);
        vector<pair<ll, ll>> p;
        for (auto &y:prime){
            if (n%y==0) p.push_back(make_pair(y, 0));
            while(n%y==0){
                p[p.size()-1].second ++;
                n /= y;
            }
        }
        /*for (auto &y:p){
            printf("%lld %lld\n", y.first, y.second);
        }*/
        if (n!=1) p.push_back(make_pair(n, 1));
        ll mex=-12345;
        for (auto &y:p){
            mex=max(mex, y.second);
        }
        printf("%lld\n", mex);
        for (ll i=mex;i>0;i--){
            ll tmp=1;
            for (auto &y:p){
                if (i<=y.second) tmp*=y.first;
            }
            printf("%lld ", tmp);
        }
        printf("\n");
    }
    return 0;
}