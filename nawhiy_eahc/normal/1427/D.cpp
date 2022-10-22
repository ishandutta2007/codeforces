#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[100];
vector<vector<int> > ans;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);

    for(int i=1; i<=n; i++){
        int idx[102] = {0};
        for(int j=1; j<=n; j++) idx[arr[j]] = j;
        int tmp = 0;
        for(int j=1; j<n; j++){
            if(idx[j] > idx[j+1]){
                tmp = j;
                break;
            }
        }
        if(!tmp) break;
        int x = idx[tmp+1], y = idx[tmp];
        int z = x;
        while(arr[x] <= arr[z]) z++;

        vector<int> ret;
        if(x>1) ret.push_back(x-1);
        ret.push_back(z-x);
        ret.push_back(y-z+1);
        if(y<n) ret.push_back(n-y);
        ans.push_back(ret);

        vector<int> vec;
        for(int i=y+1; i<=n; i++) vec.push_back(arr[i]);
        for(int i=z; i<=y; i++) vec.push_back(arr[i]);
        for(int i=x; i<z; i++) vec.push_back(arr[i]);
        for(int i=1; i<x; i++) vec.push_back(arr[i]);
        for(int i=0; i<n; i++) arr[i+1] = vec[i];
    }

    printf("%d\n", (int)ans.size());
    for(auto p: ans){
        printf("%d ", p.size());
        for(auto x: p) printf("%d ", x);
        puts("");
    }
}