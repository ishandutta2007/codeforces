#include <vector>
#include <iostream>

using namespace std;

int n;
int A[100000], f[100000], cnt[100001], _max;
int main(){
    _max = 0;
    fill(f, f + 100000, 0);
    fill(cnt, cnt + 100001, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cnt[0] = 100000;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        cnt[f[A[i-1]]]--;
        f[A[i-1]]++;
        cnt[f[A[i-1]]]++;
        _max = max(_max, f[A[i-1]]);
        if(cnt[1] == i){
            ans = i;
        }else if(_max == i){
            ans = i;
        }else if((i-_max) % (_max-1) == 0 && _max != 1 && cnt[_max-1] == (i-_max)/(_max-1) && cnt[_max] == 1){
            ans = i;
        }else if(i % _max == 1 && cnt[_max] == (i-1)/_max && cnt[1] == 1){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}