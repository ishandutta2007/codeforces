#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2000;
double DP[MAXN+1][MAXN+1], p[MAXN], q[MAXN];
int DPB[MAXN+1][MAXN+1] = {0};

void dp(double C){
    for(int i = n; i >= 0; i--){
        for(int a = 0; a <= n; a++){
            if(i == n){DP[i][a] = 0; DPB[i][a] = 0; continue;}
            pair<double,int> ans = {DP[i+1][a],DPB[i+1][a]};
            if(a > 0)ans = max(ans, {p[i] + DP[i+1][a-1], DPB[i+1][a-1]});
            ans = max(ans, {q[i] - C + DP[i+1][a], DPB[i+1][a]+1});
            if(a > 0)ans = max(ans, {p[i] + q[i] - p[i]*q[i] - C + DP[i+1][a-1], DPB[i+1][a-1]+1});
            DP[i][a] = ans.first;
            DPB[i][a] = ans.second;
        }
    }
}

int main() {
    int a,b;
    cin >> n >> a >> b;
    for(int c1 = 0; c1 < n; c1++){
       cin >> p[c1];
    }
    for(int c1 = 0; c1 < n; c1++){
       cin >> q[c1];
    }
    double l = 0.0;
    double r = n+1;
    while(abs(l-r) > 1e-8){
        double mid = (l+r)/2;
        dp(mid);
        int bopt = DPB[0][a];
        if(bopt < b)r = mid;
        if(bopt >= b)l = mid;
    }
    cout << setprecision(18) << DP[0][a]+l*b << "\n";
    return 0;
}