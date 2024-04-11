#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int cnt[100005];

int main(){

    int n;
    cin >> n;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
        cnt[sk[j]]++;
    }
    vector<int>val;
    for(int j = 1;j<=n;j++){
        if(cnt[j] == 0){
            val.push_back(j);
        }
    }
    int p = 0;
    for(int j = 0;j<n;j++){
        if(cnt[sk[j]] >= 2 || sk[j]>n){
            cnt[sk[j]]--;
            sk[j] = val[p];
            p++;
        }
        cout << sk[j] << " ";
    }
    return 0;
}