#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, pro[c], cnt[c], si;
vector<int> oszt[c];
bool v[c], ff[c];
vector<long long> sz;
long long maxi=1;
void add(int a, int b) {
    for (int x:oszt[a]) {
        if (!ff[x]) {
            if (pro[x]%2) {
                cnt[x]+=b;
            } else {
                cnt[x]-=b;
            }
        }
    }
}
int kul(int a) {
    int ans=0;
    for (int x:oszt[a]) {
        ans+=cnt[x];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (long long i=2; i<c; i++) {
        if (!oszt[i].size()) {
            for (int j=i; j<c; j+=i) {
                pro[j]++;
            }
        }
        for (int j=i; j<c; j+=i) {
            oszt[j].push_back(i);
        }
        for (long long j=i*i; j<c; j+=i*i) {
            ff[j]=1;
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int y:oszt[x]) {
            v[y]=1;
        }
    }
    v[1]=1;
    for (long long i=c-1; i>=1; i--) {
        if (v[i]) {
            while (kul(i)!=si) {
                long long x=sz.back();
                if (__gcd(i, x)==1) {
                    maxi=max(maxi, i*x);
                }
                add(x, -1);
                sz.pop_back();
                si--;
            }
            add(i, 1);
            sz.push_back(i);
            si++;
        }
    }
    cout << maxi << "\n";
    return 0;
}