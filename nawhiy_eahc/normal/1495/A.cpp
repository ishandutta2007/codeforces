#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<double> miner, dia;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n; cin >> n;
        dia.clear(); miner.clear();
        for(int i=1;i<=2*n;i++){
            double x, y; scanf("%lf %lf", &x, &y);
            if(x == 0) dia.push_back(abs(y));
            else miner.push_back(abs(x));
        }
        sort(dia.begin(), dia.end());
        sort(miner.begin(), miner.end());

        double ans = 0;
        for(int i=0;i<n;i++){
            ans += sqrt(dia[i]*dia[i] + miner[i] * miner[i]);
        }

        printf("%.12lf\n", ans);
    }
}