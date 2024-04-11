#include <bits/stdc++.h>
using namespace std;

vector<int> h;
int H, pos, n, k;

void make_slice(){
    int sum = 0;
    int po = pos;
    while(sum <= k){
        sum += (pos + 1);
        for(int j=(pos + 1); j<n; j++){
            if(h[j] >= H){
                sum++;
                po = j;
            }

            else break;
        }

        if(sum > k) break;
        H--;
        pos = po;
    }
}

int main(){
    int cnt;
    cnt = 0;
    int mi = 1e9;
    cin >> n >> k;

    h.resize(n);
    for(int i = 0; i<n; i++){
        cin >> h[i];
        mi = min(mi, h[i]);
    }

    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    H = h[0];
    pos = 0;

    int p[n + 1];
    p[0] = 0;

    while(H > mi){
        make_slice();
        cnt++;
    }

    cout << cnt;



}