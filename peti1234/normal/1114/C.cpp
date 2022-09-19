#include <bits/stdc++.h>

using namespace std;
long long a, b;
long long sum;
long long maxi=1;
long long mini=-1;
vector<pair<long long, long long >> v;
bool pr[1000001];
int main()
{
    cin >> a >> b;
    for (int i=2; i<=1000000; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<=1000000; j+=i) {
                pr[j]=true;
            }
        }
    }
    for (long long i=2; i*i<=b; i++) {
        if (!pr[i]) {
            long long q=0;
            while (b%i==0) {
                q++;
                b/=i;
            }
            if (q!=0) {
                v.push_back({i, q});
            }
        }
    }
    if (b!=1) {
        v.push_back({b, 1});
    }
    for (int i=0; i<v.size(); i++) {
        long long y=a;
        long long fi=v[i].first;
        long long se=v[i].second;
        long long re=0;
        while(y>0) {
            long long x=y/fi;
            re+=x;
            y=x;
        }
        if (mini==-1) {
            mini=re/se;
        }
        mini=min(mini, re/se);
    }
    cout << mini << endl;
    return 0;
}
// 123456797587654321 123456121321