#include <iostream>
using namespace std;
typedef long long ll;
int max_bit(int n){
    int _max = 0;
    while(n >> _max){
        _max++;
    }
    return _max;
}

int test(int n){
    for(int i=0;i<40;i++){
        if((ll)n == (ll)((1 << i)-1)){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int ans[20];
    while(!test(n)){
        int res = max_bit(n);
        ans[cnt/2] = res;
        n = n ^ ((2 << (res-1)) - 1);
        cnt++;
        if(test(n)){
            break;
        }
        n++;
        cnt++;
    }
    cout << cnt << endl;
    for(int i=0;i<(cnt+1)/2;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}