#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

double pi = atan(1)*4;

int main()
{
    int n;
    cin >> n;
    double sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    sort(sk,sk+n);
    double l = 0;
    for(int i = 0;i<n;i++){
        if(i%2==0){
            l += sk[i]*sk[i]*pi;
        }
        else{
            l -= sk[i]*sk[i]*pi;
        }
    }
    cout << fixed << setprecision(5) << abs(l);
    return 0;
}