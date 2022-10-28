#include "bits/stdc++.h"
using namespace std;
const int arr[16][4] = {
    {0 , 0 , 0 , 0} , //0
    {0 , 0 , 0 , 1} , 
    {0 , 0 , 1 , 0} ,
    {0 , 0 , 1 , 1} ,
    {0 , 1 , 0 , 0} , //4
    {0 , 1 , 0 , 1} ,
    {0 , 1 , 1 , 0} ,
    {0 , 1 , 1 , 1} ,
    {1 , 0 , 0 , 0} , //8
    {1 , 0 , 0 , 1} ,
    {1 , 0 , 1 , 0} ,
    {1 , 0 , 1 , 1} ,
    {1 , 1 , 0 , 0} , //12
    {1 , 1 , 0 , 1} ,
    {1 , 1 , 1 , 0} ,
    {1 , 1 , 1 , 1}
};
const int ans[16] = {0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 1 , 1 , 0 , 1 , 1};
int a[4];
int main(){
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int idx = 0;
    for(int i = 0 ; i < 16 ; ++i){
        if(arr[i][0] == a[0] && arr[i][1] == a[1] && arr[i][2] == a[2] && arr[i][3] == a[3]){
            idx = i;
        }
    }
    if(idx == 6){
        cout << ans[6] << endl;
        return 0;
    }
    if(idx == 0){
        cout << ans[0] << endl;
        return 0;
    }
    if(idx == 8){
        cout << ans[8] << endl;
        return 0;
    }
    if(idx == 4){
        cout << ans[4] << endl;
        return 0;
    }
    if(idx == 12){
        cout << ans[12] << endl;
        return 0;
    }
    if(idx == 2){
        cout << ans[2] << endl;
        return 0;
    }
    if(idx == 10){
        cout << ans[10] << endl;
        return 0;
    }
    if(idx == 14){
        cout << ans[14] << endl;
        return 0;
    } 
    if(idx == 1){
        cout << ans[1] << endl;
        return 0;
    }
    if(idx == 9){
        cout << ans[9] << endl;
        return 0;
    }
    if(idx == 5){
        cout << ans[5] << endl;
        return 0;
    }
    if(idx == 13){
        cout << ans[13] << endl;
        return 0;
    }
    if(idx == 3){
        cout << ans[3] << endl;
        return 0;
    }
    if(idx == 11){
        cout << ans[11] << endl;
        return 0;
    }
    if(idx == 7){
        cout << ans[7] << endl;
        return 0;
    }
    if(idx == 15){
        cout << ans[15] << endl;
        return 0;
    }
}