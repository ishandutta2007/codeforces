#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int D = 205;
int arr[N];
vector < int > v[N];
int cnt[D] = {0};
int sum = 0;
int n;
int inp;
int ele;
int maxe = 0;
int ans = INT_MAX;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        maxe = max(maxe , arr[i]);
    }
    ele = n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp;
        cnt[inp]++;
        v[arr[i]].emplace_back(inp);
    }
    for(int i = N - 1 ; i >= 1 ; --i){
        int count = v[i].size();
        if(!count){
            continue;
        }
        for(int x : v[i]){
            cnt[x]--;
        }
        if(count > ele / 2){
            ans = min(ans , sum);
        }
        else{
            int req = count * 2 - 1;
            req = ele - req;
            int j = 1;
            int extra = 0;
            while(req > 0 && j <= 200){
                if(cnt[j] >= req){
                    extra += req * j;
                    req = 0;
                }
                else{
                    extra += cnt[j] * j;
                    req -= cnt[j];
                }
                ++j;
            }
            if(!req){
                ans = min(ans , sum + extra);
            }
        }
        for(int x : v[i]){
            sum += x;
        }
        ele -= count;
    }
    cout << ans;
}