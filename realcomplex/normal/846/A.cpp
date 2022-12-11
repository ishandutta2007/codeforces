#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    vector<int>sub[n];
    sub[0].push_back(sk[0]);
    for(int i = 1;i<n;i++){
        for(int x = 0;x<i;x++){
            if((sk[x] <= sk[i]) && (sub[i].size() < sub[x].size() + 1)){
                sub[i] = sub[x];
            }
        }
        sub[i].push_back(sk[i]);
    }
    int mx = 0;
    for(int i = 0;i<n;i++){
        if(sub[i].size() > mx){
            mx = sub[i].size();
        }
    }
    cout << mx;
	return 0;
}