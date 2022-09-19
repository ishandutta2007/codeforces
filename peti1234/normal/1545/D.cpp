#include <bits/stdc++.h>

using namespace std;
long long sum[1005][2], n, m, spec, db, kul, kul2, dif;
long long calc(int a, int b) {
    return sum[a][b]+sum[a+2][b]-2*sum[a+1][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            long long x;
            cin >> x;
            sum[i][0]+=x, sum[i][1]+=x*x;
        }
    }
    for (int i=1; i<=n-2; i++) {
        if (calc(i, 0)) {
            spec=i;
            db++;
        }
    }
    if (spec==n-2) {
        spec+=3-db;
    }
    dif=(spec>=4 ? calc(1, 1) : calc(n-2, 1));
    kul=(spec>=3 ? calc(spec-2, 0) : calc(spec, 0));
    kul2=(spec>=3 ? calc(spec-2, 1) : calc(spec, 1))-dif;
    cout << spec-1 << " " << (kul2-kul*kul)/(2*kul) << "\n";
    return 0;
}