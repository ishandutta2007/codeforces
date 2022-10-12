#include <bits/stdc++.h>
using namespace std;

int n, l, v1, v2, k;

bool check (double t) {
    double bus = 0;
    double pupil = 0;
    double total = 0;
    for (int i=0; i<n; i+=k) {
        double tmp = (bus - pupil) / (v1 + v2);
        
        pupil = min(pupil + tmp * v1, (double) l);
        bus = min(pupil + t * v2, (double) l);
        pupil = min(pupil + t * v1, (double) l);
        
        total += tmp + t;
    }
    
    // cout << t << " " << total << endl;
    return t + max((l - t * v2), 0.0) / v1 < total;
}

int main() {
    scanf ("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
    
    double ki = (double) 0;
    double ka = (double) l / v2;
    for (int i=0; i<60; i++) {
        double mid = (ki + ka) / 2;
        
        if (check(mid)) ka = mid;
        else ki = mid;
    }
    
    printf ("%.12lf\n", ki + (l - ki * v2) / v1);
    return 0;
}