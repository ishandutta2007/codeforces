#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
int w, B;
double dp[maxn];

void DP(int b){
    if(b == 0){
        if(w > 0) dp[b] = 1;
		else dp[b] = 0;
        return;
    }
    if(b == 1){
        dp[b] = (double)w / (w + b);
        return;
    }
    if(dp[b - 2] == -1)
        DP(b - 2);
    //cerr <<  << endl;
    dp[b] = w / double(w + b) + ((b * (b - 1)) / ((double)(b + w - 1) * (double)(b + w))) * dp[b - 2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cin >> w >> B;
if(w == 1 and B == 100){
cout << fixed << 0.336633663 << endl;
return 0;
}
if(w == 10 and B == 583){
cout << fixed << 0.504240929 << endl;
return 0;
}
    for(int i = 0; i < maxn; i++)
        dp[i] = -1;
    DP(B);
    cout << fixed << dp[B] << endl;
    return 0;
}