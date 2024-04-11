#include <iostream>
#include <string.h>
#include <vector>
#define sz(n) (int)n.size()
using namespace std;
int main(){
    int m, n;
    cin >> n >> m;
    int ans[2];
    ans[0] = n/m;
    ans[1] = 0;
    int cnt[2001];
    fill(cnt, cnt+m+1, n/m);
    int arr[2000];
    vector<int> free;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        arr[i] = v;
        if(v > m){
            free.push_back(i);
            continue;
        }
        if(cnt[v]){
            cnt[v]--;
        }else{
            free.push_back(i);
            continue;
        }
    }
    int ind = 1;
    bool End = false;
    for(auto i:free){
        while(cnt[ind]==0){
            if(ind == m){
                End = true;
                break;
            }
            ind++;
        }
        if(End){
            break;
        }
        arr[i] = ind;
        ans[1]++;
        cnt[ind]--;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}