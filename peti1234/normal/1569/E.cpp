#include <bits/stdc++.h>

using namespace std;
const int c=35;
long long n, f, cnt, n2, po[c], ans[c], A, H, mod=998244353;
map<long long, long long> m[2];
long long s(int a, int b) {
    if (!b) {
        b=1;
    } else {
        b=(1<<(b-1))+1;
    }
    ans[a]=b;
    return a*po[b]%mod;
}
long long calc(vector<pair<int, int> > &sz, int mask) {
    long long sum=0;
    for (int i=0; i<cnt; i++) {
        int x=sz[2*i].first, y=sz[2*i+1].first, id=sz[2*i].second;
        if (mask & (1<<i)) {
            sum+=s(y, id);
            sz.push_back({x, id-1});
        } else {
            sum+=s(x, id);
            sz.push_back({y, id-1});
        }
    }
    return sum%mod;
}
int main()
{
    cin >> n >> A >> H;
    n2=(1<<n), f=n2/2, cnt=f-1;
    po[0]=1;
    for (int i=1; i<=n2; i++) {
        po[i]=po[i-1]*A%mod;
    }


    for (int w=0; w<2; w++) {
        for (int cs=0; cs<2; cs++) {
            for (int mask=0; mask<(1<<cnt); mask++) {
                vector<pair<int, int> > sz;
                for (int i=1; i<=f; i++) {
                    sz.push_back({i+cs*f, n});
                }
                long long sum=calc(sz, mask);

                int p=(w==cs);
                sum+=s(sz.back().first, p);
                sum%=mod;
                //cout << "ertek " << w << " " << mask << " " << cs << " " << sum << "\n";
                m[cs][sum]=mask;
            }
        }
        for (auto x:m[0]) {
            long long fi=x.first, r1=x.second, kul=(H+mod-fi)%mod;
            if (m[1].find(kul)!=m[1].end()) {
                long long r2=m[1][kul];
                vector<pair<int, int> > sz;
                for (int i=1; i<=f; i++) {
                    sz.push_back({i, n});
                }
                calc(sz, r1);
                ans[sz.back().first]=(w ? 1 : 2);


                sz.clear();
                for (int i=1; i<=f; i++) {
                    sz.push_back({i+f, n});
                }
                calc(sz, r2);
                ans[sz.back().first]=(w ? 2 : 1);

                for (int i=1; i<=n2; i++) {
                    cout << ans[i] << " ";
                }
                cout << "\n";
                return 0;
            }
        }

        m[0].clear(), m[1].clear();
    }

    cout << -1 << "\n";
    return 0;
}
/*
1 10 210
*/