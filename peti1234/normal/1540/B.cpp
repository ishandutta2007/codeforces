#include <bits/stdc++.h>

using namespace std;
const int c=202;
int n, dist[c][c];
long long pre[c][c], mod=1000000007, ans;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        pre[0][i]=1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            pre[i][j]=(pre[i-1][j]+pre[i][j-1])*(mod+1)/2;
            pre[i][j]%=mod;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j]=c;
        }
        dist[i][i]=0;
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b]=1, dist[b][a]=1;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int tav=dist[i][j];
            for (int k=1; k<=n; k++) {
                int dif=dist[j][k]-dist[i][k];
                if (dif>=tav) {
                    continue;
                }
                if (dif<=-tav) {
                    //cout << "rossz " << i << " " << j << " " << k << "\n";
                    ans++;
                } else {
                    long long s=(tav+dif)/2;
                    //cout << "kozepes " << i << " " << j << " " << k << "\n";
                    //cout << "ertek " << s << " " << tav-s <<"\n";
                    ans+=pre[s][tav-s]%mod;
                }
                ans%=mod;
            }
        }
    }
    ans*=oszt(n);
    ans%=mod;
    cout << ans << "\n";
    return 0;
}