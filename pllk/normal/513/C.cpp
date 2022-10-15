#include <iostream>
#include <cstdio>

using namespace std;

int n;
int l[5], r[5];
double ee;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    for (int i = 1; i <= 10000; i++) {
        for (int b = 1; b < (1<<n); b++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (b&(1<<j)) c++;
            }
            if (c == 1) continue;
            double tn = 1;
            for (int j = 0; j < n; j++) {
                if (b&(1<<j)) {
                    if (l[j] <= i && i <= r[j]) {
                        tn *= (double)1/(r[j]-l[j]+1);
                    } else {
                        tn = 0;
                    }
                } else {
                    if (l[j] < i) {
                        tn *= (double)(min(r[j],i-1)-l[j]+1)/(r[j]-l[j]+1);
                    } else {
                        tn = 0;
                    }
                }
            }
            ee += tn*i;
        }
    }
    for (int v = 0; v < n; v++) {
        for (int i = 1; i <= 10000; i++) {
            if (r[v] <= i) continue;
            for (int b = 1; b < (1<<n); b++) {
                double tn = (double)(r[v]-max(i+1,l[v])+1)/(r[v]-l[v]+1);
                for (int j = 0; j < n; j++) {
                    if (b&(1<<j)) {
                        if (j == v) tn = 0;
                        if (l[j] <= i && i <= r[j]) {
                            tn *= (double)1/(r[j]-l[j]+1);
                        } else {
                            tn = 0;
                        }
                    } else {
                        if (j == v) continue;
                        if (l[j] >= i) {
                            tn = 0;
                        } else {
                            tn *= (double)(min(r[j],i-1)-l[j]+1)/(r[j]-l[j]+1);
                        }
                    }
                }
                ee += i*tn;
            }
        }
    }
    printf("%.12lf\n", ee);
}