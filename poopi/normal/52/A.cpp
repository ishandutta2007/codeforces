#include<iostream>
using namespace std;

int cnt[4];
int main(){
    int n, a, mx = 0;     
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[a]++;
        mx = max(mx, cnt[a]);
    }
    cout << n - mx << endl;
    return 0;
}