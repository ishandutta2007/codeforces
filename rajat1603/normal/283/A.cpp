#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
long long sum;
long long lazy[N];
long long arr[N];
int cur;
int n;
int type;
long long inp , x;
void pre(){
    memset(lazy , 0 , sizeof(lazy));
    cur = 1;
    arr[1] = 0;
    sum = 0;
}
int main(){
    pre();
    cin >> n;
    while(n--){
        cin >> type;
        if(type == 1){
            cin >> inp >> x;
            sum += inp * x;
            lazy[inp] += x;
        }
        else if(type == 2){
            cin >> arr[++cur];
            sum += arr[cur];
        }
        else{
            lazy[cur - 1] += lazy[cur];
            arr[cur] += lazy[cur];
            lazy[cur] = 0;
            sum -= arr[cur--];
        }
        printf("%.6lf\n" , 1.0 * sum / cur);
    }
}