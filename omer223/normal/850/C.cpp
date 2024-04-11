//
// Created by omero on 11/27/2020.
//

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

typedef long long ll;
int n;
unordered_map<int, int> mem, dp;

void decom(int x) {
    for (int i = 2; i * i <= x; i++) {
        if(x%i==0){
            int cnt = 0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            mem[i]|=(1<<(cnt-1));
        }
    }
    if(x!=1)mem[x]|=1;
}

int calcGrundy(int msk) {
    if(!msk)return 0;
    else if (dp.count(msk))return dp[msk];
    set<int> s;
    int tmsk = msk, tmp;
    for (int i = 0; tmsk and i < 32; i++) {
        tmp = (msk>>(i+1)) | (msk & ((1<<i) - 1));
        if(!dp.count(tmp)); dp[tmp] = calcGrundy(tmp);
        s.insert(dp[tmp]);
        tmsk>>=1;
    }
    int lookingFor=0;
    for (int x : s){
        if(x==lookingFor)lookingFor++;
        else break;
    }
    dp[msk]=lookingFor;
    return lookingFor;
}

int main() {
    fast;
    cin >> n;
    int tmp;
    calcGrundy((1<<31)-1);
    foru(i,0,n){cin>>tmp;decom(tmp);}
    int ret=0;
    for (auto x : mem)
        ret^=calcGrundy(x.second);
    cout<<(!ret?"Arpa":"Mojtaba")<<'\n';
    return 0;
}