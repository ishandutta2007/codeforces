#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[102];
vector<int> vec;
vector<int> ans;
bool chk[1000002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vec.clear();
        ans.clear();
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            for(int j=1; j<i; j++){
                vec.push_back(abs(arr[i] - arr[j]));
            }
        }
        memset(chk, 0, sizeof(chk));
        ans.push_back(1);
        for(auto x: vec) chk[x+1] = 1;

        int pnt = 2;
        for(int i=1; i<n; i++){
            while(pnt <= 1000000 && chk[pnt]) pnt++;
            if(pnt > 1000000) break;
            ans.push_back(pnt);
            for(auto x: vec) chk[x+pnt] = 1;
            pnt++;
        }

        if((int)ans.size() < n){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1; i<=n; i++){
            printf("%d ", ans[i-1]);
        }
        printf("\n");
    }
}