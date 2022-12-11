#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc ;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        ld l;
        cin >> n >> l;
        vector<ld> p(n + 2);
        p[0] = 0;
        p[n+1] = l;
        for(int i = 1; i <= n; i ++ ){
            cin >> p[i];
        }
        vector<ld> T(n+2), TT(n+2);
        T[0]=0;
        for(int i = 1; i <= n + 1; i ++ ){
            T[i] = T[i-1]+(p[i]-p[i-1])/(ld)i;
        }
        ld sol = -1.0;
        for(int i = n; i >= 0 ; i -- ){
            TT[i] = TT[i+1] + (p[i+1]-p[i])/(ld)(n+1-i);
            if(T[i] == TT[i]){
                sol = T[i];
                break;
            }
        }
        if(sol < 0){
            ld p0, p1;
            int cut = -1;
            for(int i = 1;i <= n+1; i ++ ){
                if(T[i] > TT[i]){
                    cut = i-1;
                    break;
                }
            }
            p0 = p[cut];
            p1 = p[cut+1];
            ld mx = max(T[cut], TT[cut+1]);
            ld s0 = cut + 1;
            ld s1 = n + 1 - cut;
            p0 += (mx-T[cut])*s0;
            p1 -= (mx-TT[cut+1])*s1;
            mx += (p1-p0)/(s0+s1);
            cout << fixed << setprecision(10) << mx << "\n";
        }
        else{
            cout << fixed << setprecision(10) << sol << "\n";
        }

    }
    return 0;
}