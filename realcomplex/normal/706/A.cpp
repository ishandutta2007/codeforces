#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    double x,y;
    cin >> x >> y;
    int n;
    cin >> n;
    double dist;
    double mSpeed;
    double mTime = 1e9;
    int c1,c2;
    for(int i = 0;i<n;i++){
        cin >> c1 >> c2 >> mSpeed;
        dist = sqrt(pow(abs(c1-x),2)+pow(abs(c2-y),2));
        mTime = min(mTime,dist/mSpeed);
    }
    cout << setprecision(7)<< mTime;
    return 0;
}