#include<bits/stdc++.h>
using namespace std;

const int c=100005, k=18;
long long n, w, tav[c][k][2][2], x[c][2], y[c][2], sok=1e15;
long long dist(int a, int b, int c, int d) {
    return abs(a-c)+abs(b-d);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        for (int j=0; j<2; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    for (int i=1; i<n; i++) {
        for (int kezd=0; kezd<2; kezd++) {
            int a=x[i][kezd], b=y[i][kezd];
            if (kezd==0) a++;
            else b++;
            for (int kov=0; kov<2; kov++) {
                tav[i][0][kezd][kov]=1+dist(a, b, x[i+1][kov], y[i+1][kov]);
            }
        }
    }
    for (int j=1; j<k; j++) {
        for (int i=1; i<n; i++) {
            int cs=i+(1<<(j-1));
            if (cs>=n) continue;
            for (int kezd=0; kezd<2; kezd++) {
                for (int veg=0; veg<2; veg++) {
                    tav[i][j][kezd][veg]=min(tav[i][j-1][kezd][0]+tav[cs][j-1][0][veg], tav[i][j-1][kezd][1]+tav[cs][j-1][1][veg]);
                }
            }
        }
    }
    cin >> w;
    while (w--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int pos=max(x1, y1), cel=max(x2, y2);
        if (pos>cel) {
            swap(x1, x2);
            swap(y1, y2);
            swap(pos, cel);
        }
        if (pos==cel) {
            //cout << "konnyu.........: ";
            cout << dist(x1, y1, x2, y2) << "\n";
            continue;
        }
        long long regi[2], uj[2];
        for (int i=0; i<2; i++) {
            regi[i]=dist(x1, y1, x[pos][i], y[pos][i]);
        }
        for (int j=k-1; j>=0; j--) {
            int kov=pos+(1<<j);
            if (kov>=cel) continue;
            for (int ert=0; ert<2; ert++) {
                uj[ert]=min(regi[0]+tav[pos][j][0][ert], regi[1]+tav[pos][j][1][ert]);
            }
            regi[0]=uj[0], regi[1]=uj[1];
            pos=kov;
        }
        long long ans=sok;
        for (int el=0; el<2; el++) {
            int a=x[cel-1][el], b=y[cel-1][el];
            if (el==0) a++;
            else b++;
            ans=min(ans, 1+regi[el]+dist(a, b, x2, y2));
        }
        //cout << "nehez..........: ";
        cout << ans << "\n";
    }
	return 0;
}
/*
2
1 1 1 1
1
1 1 1 2
*/