#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    sort(sk,sk+n);
    int sum = 0;
    for(int i = 1;i<n;i++){
        for(int y = i;y>0;y--){
            while(sk[y] > sk[y-1] || sk[y-1] > sk[y]){
                if(sk[y] > sk[y-1]){
                    sk[y] = sk[y]-sk[y-1];
                }
                else{
                    sk[y-1] = sk[y-1]-sk[y];
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        sum += sk[i];
    }
    cout << sum;
    return 0;
}