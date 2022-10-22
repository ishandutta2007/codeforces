#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, k;
bool arr[100002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++){
            char c;
            scanf(" %c", &c);
            arr[i] = (c == 'W');
        }
        vector<int> vec;
        for(int i=1; i<=n; i++){
            if(arr[i]) continue;
            int j = i;
            while(j<n && !arr[j+1]) j++;
            if(i!=1 && j!=n) vec.push_back(j-i+1);
            i=j;
        }

        sort(vec.begin(), vec.end());
        int ans = 0, zeroCnt = 0;
        for(int i=1; i<=n; i++){
            if(arr[i]) ans += 1 + (arr[i-1] == 1);
            else zeroCnt++;
        }

        if(zeroCnt <= k){
            printf("%d\n", 2*n-1);
            continue;
        }
        if(zeroCnt == n){
            printf("%d\n", max(0, 2*k-1));
            continue;
        }
        ans += k * 2;

        for(auto p: vec){
            if(k >= p){
                k -= p;
                ans++;
            }
            else break;
        }
        printf("%d\n", ans);
    }
}