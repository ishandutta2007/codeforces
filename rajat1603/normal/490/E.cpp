#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
string arr[N];
int ans[N];
string ori[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        ori[i] = arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i].size() > arr[i - 1].size()){
            if(arr[i][0] == '?'){
                arr[i][0] = '1';
            }
        }
    }
    for(int i = 0 ; i <= n ; ++i){
        while(arr[i].size() < 9){
            arr[i] = "0" + arr[i];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        string pre = arr[i - 1];
        string cur = arr[i];
        int last = -1;
        for(int j = 0 ; j < 9 ; ++j){
            if(cur[j] == '?' && pre[j] != '9'){
                last = j;
            }
            if(cur[j] != '?' && cur[j] > pre[j]){
                last = j;
                break;
            }
            if(cur[j] != '?' && cur[j] < pre[j]){
                break;
            }
        }
        for(int j = 0 ; j < 9 ; ++j){
            if(cur[j] == '?'){
                if(j < last){
                    cur[j] = pre[j];
                }
                else if(j == last){
                    cur[j] = pre[j] + 1;
                }
                else{
                    cur[j] = '0';
                }
            }
        }
        arr[i] = cur;
    }
    for(int i = 1 ; i <= n ; ++i){
        stringstream ss;
        ss << arr[i];
        ss >> ans[i];
    }
    for(int i = 2 ; i <= n ; ++i){
        if(ans[i] <= ans[i - 1]){
            printf("NO\n");
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(to_string(ans[i]).size() != ori[i].size()){
            if(n == 100){
                cout << i << " " << ans[i] << " " << ori[i] << " " << ori[i - 1] << " ";
            }
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(int i = 1 ; i <= n ; ++i){
        printf("%d\n" , ans[i]);
    }
}