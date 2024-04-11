#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans;
    ans=0;
    int arr[3];
    cin >> n;

    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            arr[0]=a;
            arr[1]=b;
            arr[2]=a^b;
            if(arr[2]<=n){
                sort(arr, arr + 3);
                if(arr[2]<arr[0]+arr[1]) ans++;
            }
        }
    }

    cout << ans/6;

}